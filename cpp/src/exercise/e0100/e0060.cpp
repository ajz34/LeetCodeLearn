// https://leetcode-cn.com/problems/permutation-sequence/

#include "extern.h"

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> prod{ 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
        vector<int> v; for (int i = 1; i <= n; ++i) v.push_back(i);
        string result;
        k -= 1;
        for (int i = n - 2; i >= 0; --i) {
            result.push_back('0' + v[k / prod[i]]);
            v.erase(v.begin() + k / prod[i]);
            k %= prod[i];
        }
        result.push_back('0' + v[0]);
        return result;
    }
};

TEST(e0100, e0060) {
    ASSERT_EQ(Solution().getPermutation(3, 3), "213");
    ASSERT_EQ(Solution().getPermutation(4, 9), "2314");
}
