// https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/

// 耗时：0:08:49
// 错误次数：1
// 错误原因：极端情况未考虑

#include "extern.h"

class LCOF4000 {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (arr.size() <= k) return arr;
        if (k == 0) return {};
        priority_queue<int> que;
        for (auto a : arr) {
            if (que.size() < k)
                que.push(a);
            else if (a < que.top()) {
                que.push(a);
                que.pop();
            }
        }
        vector<int> result;
        while (!que.empty()) {
            result.push_back(que.top());
            que.pop();
        }
        return result;
    }
};

TEST(lcof, lcof4000) {
    vector<int> arr, ans;
    arr = str_to_vec<int>("[3,2,1]");
    ans = str_to_vec<int>("[2,1]");
    ASSERT_THAT(vec_to_set(LCOF4000().getLeastNumbers(arr, 2)), vec_to_set(ans));
    arr = str_to_vec<int>("[0,1,2,1]");
    ans = str_to_vec<int>("[0]");
    ASSERT_THAT(vec_to_set(LCOF4000().getLeastNumbers(arr, 1)), vec_to_set(ans));
}
