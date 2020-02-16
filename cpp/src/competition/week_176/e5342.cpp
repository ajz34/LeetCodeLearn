// https://leetcode-cn.com/problems/maximum-number-of-events-that-can-be-attended/

#include "extern.h"

class Solution {
    struct sortEvents {
        inline bool operator()(vector<int>& e1, vector<int>& e2) {
            assert(e1.size() == 2 && e2.size() == 2);
            if (e1[0] > e2[0]) return true;
            else if (e1[0] < e2[0]) return false;
            else return e1[1] > e2[1];
        }
    };
public:
    int maxEvents(vector<vector<int>>& events) {
        int result = 0;
        sort(events.begin(), events.end(), sortEvents());
        while (!events.empty()) {
            ++result;
            int current_date = events.back()[0];
            events.pop_back();
            for (size_t idx = events.size(); idx-- > 0; ) {
                if (events[idx][0] == current_date && events[idx][1] == current_date) events.pop_back();
                else if (events[idx][0] == current_date) events[idx][0] += 1;
                else if (events[idx][0] > current_date + 1) {
                    sort(events.begin() + idx, events.end(), sortEvents());
                    break;
                }
            }
            if (!events.empty() && events[0][0] <= current_date + 1) sort(events.begin(), events.end(), sortEvents());
        }
        return result;
    }
};

TEST(week176, e5342) {
    auto m = str_to_mat<int>("[[1,2],[2,3],[3,4],[1,2]]");
    ASSERT_EQ(Solution().maxEvents(m), 4);
    m = str_to_mat<int>("[[1,4],[4,4],[2,2],[3,4],[1,1]]");
    ASSERT_EQ(Solution().maxEvents(m), 4);
    m = str_to_mat<int>("[[1,100000]]");
    ASSERT_EQ(Solution().maxEvents(m), 1);
    m = str_to_mat<int>("[[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]]");
    ASSERT_EQ(Solution().maxEvents(m), 7);
}

/*  简要注释：
    
    这是一个贪心算法的典型应用。

    我们首先将会议进行排序，排序依据是：会议首日优先从小到大，会议末日随后从小到大排序。
    譬如 [1, 3] < [1, 4] < [2, 2] < [3, 4] < [4, 4]
    随后我们选择最小的会议 [1, 3]；以后我们就不必关心这个会议，并且进入第二天的议程。

    在进入第二天之前，我们需要将会议的首日统一调整到至少为 2，即将 [1, 4] 调整为 [2, 4]，
    那么这样就会对会议优先级产生影响，进而为 [2, 2] < [(1->2), 4] < [3, 4] < [4, 4]。
    我们将首先参加 [2, 2] 的会议。
    
    随后类似地，给出第三天排序 [(1->2->3), 4] < [3, 4] < [4, 4]。以此类推。
*/