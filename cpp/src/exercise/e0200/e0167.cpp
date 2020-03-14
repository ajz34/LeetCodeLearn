// https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/

#include "extern.h"

class S0167 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers.size() < 2) return {};
        int l = 0, r = numbers.size() - 1;
        vector<int>::iterator p;
        while (l < r) {
            if (numbers[l] + numbers[r] == target)
                return { l + 1, r + 1 };
            else if (numbers[l] + numbers[r] > target) {
                p = upper_bound(numbers.begin() + l + 1, numbers.begin() + r, target - numbers[l]);
                r = prev(p) - numbers.begin();
            }
            else {
                p = lower_bound(numbers.begin() + l + 1, numbers.begin() + r, target - numbers[r]);
                l = p - numbers.begin();
            }
        }
        return {};
    }
};

TEST(e0200, e0167) {
    vector<int> numbers = str_to_vec<int>("[2,7,11,15]");
    vector<int> ans = { 1, 2 };
    ASSERT_THAT(S0167().twoSum(numbers, 9), ans);
}

/* ÆÀÂÛ
   https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/solution/liang-shu-zhi-he-ii-shu-ru-you-xu-shu-zu-by-leetco/285967
*/
