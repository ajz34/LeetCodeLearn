// https://leetcode-cn.com/problems/pascals-triangle-ii/

#include "extern.h"

class S0119 {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return { 1 };
        if (rowIndex == 1) return { 1, 1 };
        vector<long long> vec_prev, vec_cur{ 1, 1 };
        for (int i = 0; i < rowIndex - 1; ++i) {
            swap(vec_prev, vec_cur);
            vec_cur.clear();
            vec_cur.push_back(1);
            for (int j = 0; j < vec_prev.size() - 1; ++j)
                vec_cur.push_back(vec_prev[j] + vec_prev[j + 1]);
            vec_cur.push_back(1);
        }
        return vector<int>(vec_cur.cbegin(), vec_cur.cend());
    }
};

TEST(e0200, e0119) {
    auto res = S0119().getRow(3);
    auto ans = str_to_vec<int>("[1,3,3,1]");
    ASSERT_THAT(res, ans);
}
