// https://leetcode-cn.com/problems/sorted-merge-lcci/

// 耗时：0:07:08
// 错误次数：1
// 错误类型：极端情况失误

#include "extern.h"

class LCCI1001 {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int pA = m - 1, pB = n - 1, p = m + n - 1;
        while (p >= 0) {
            if (pB < 0) A[p--] = A[pA--];
            else if (pA < 0) A[p--] = B[pB--];
            else if (pB < 0 || A[pA] > B[pB]) A[p--] = A[pA--];
            else A[p--] = B[pB--];
        }
    }
};

TEST(lcci, lcci1001) {
    vector<int> A = str_to_vec<int>("[1,2,3,0,0,0]");
    vector<int> B = str_to_vec<int>("[2,5,6]");
    vector<int> ans = str_to_vec<int>("[1,2,2,3,5,6]");
    LCCI1001().merge(A, 3, B, 3);
    ASSERT_THAT(A, ans);
}
