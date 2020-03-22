// https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique/

#include "extern.h"

class S0945 {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int result = 0;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] <= A[i - 1]) {
                result += A[i - 1] + 1 - A[i];
                A[i] = A[i - 1] + 1;
            }
        }
        return result;
    }
};

TEST(e1000, e0945) {
    vector<int> A;
    A = str_to_vec<int>("[1,2,2]");
    ASSERT_EQ(S0945().minIncrementForUnique(A), 1);
    A = str_to_vec<int>("[3,2,1,2,1,7]");
    ASSERT_EQ(S0945().minIncrementForUnique(A), 6);

}
