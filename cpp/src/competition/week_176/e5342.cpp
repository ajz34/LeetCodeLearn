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

/*  ��Ҫע�ͣ�
    
    ����һ��̰���㷨�ĵ���Ӧ�á�

    �������Ƚ���������������������ǣ������������ȴ�С���󣬻���ĩ������С��������
    Ʃ�� [1, 3] < [1, 4] < [2, 2] < [3, 4] < [4, 4]
    �������ѡ����С�Ļ��� [1, 3]���Ժ����ǾͲ��ع���������飬���ҽ���ڶ������̡�

    �ڽ���ڶ���֮ǰ��������Ҫ�����������ͳһ����������Ϊ 2������ [1, 4] ����Ϊ [2, 4]��
    ��ô�����ͻ�Ի������ȼ�����Ӱ�죬����Ϊ [2, 2] < [(1->2), 4] < [3, 4] < [4, 4]��
    ���ǽ����Ȳμ� [2, 2] �Ļ��顣
    
    ������Ƶأ��������������� [(1->2->3), 4] < [3, 4] < [4, 4]���Դ����ơ�
*/