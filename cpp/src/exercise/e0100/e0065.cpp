// https://leetcode-cn.com/problems/plus-one/

#include "extern.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (auto pd = digits.rbegin(); pd != digits.rend(); ++pd) {
            *pd += 1;
            if (*pd == 10) *pd = 0;
            else return digits;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

TEST(e0100, e0065) {
    vector<int> digits, ans;
    digits = str_to_vec<int>("[1,2,3]");
    ans = str_to_vec<int>("[1,2,4]");
    ASSERT_THAT(Solution().plusOne(digits), ans);
    digits = str_to_vec<int>("[4,3,2,1]");
    ans = str_to_vec<int>("[4,3,2,2]");
    ASSERT_THAT(Solution().plusOne(digits), ans);
    digits = str_to_vec<int>("[9,9,9,9]");
    ans = str_to_vec<int>("[1,0,0,0,0]");
    ASSERT_THAT(Solution().plusOne(digits), ans);
}
