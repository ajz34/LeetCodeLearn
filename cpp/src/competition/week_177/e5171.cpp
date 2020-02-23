// https://leetcode-cn.com/problems/closest-divisors/

#include "extern.h"

class Solution {
public:
    vector<int> closestDivisors(int num) {
        int l = sqrt(num + 2);
        int r = l;
        while (l * r - num != 1 && l * r - num != 2) {
            if (r * l <= num) ++r;
            else --l;
        }
        return { l, r };
    }
};

TEST(week177, e5171) {
    vector<int> ans = str_to_vec<int>("[3,3]");
    ASSERT_THAT(Solution().closestDivisors(8), ans);
    ans = str_to_vec<int>("[5,25]");
    ASSERT_THAT(Solution().closestDivisors(123), ans);
    ans = str_to_vec<int>("[25,40]");
    ASSERT_THAT(Solution().closestDivisors(999), ans);
}
