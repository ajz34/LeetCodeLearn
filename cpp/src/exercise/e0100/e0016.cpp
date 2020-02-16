#include "extern.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Similar to e0015
        int result = -1000000;  // a very impossible number
        sort(nums.begin(), nums.end());
        auto update = [&result, &nums, &target] (int a, int b, int c) {
            if (abs(nums[a] + nums[b] + nums[c] - target) < abs(result - target))
                result = nums[a] + nums[b] + nums[c];
        };
        for (size_t c = nums.size() - 1; c >= 2;) {
            for (size_t a = 0, b = c - 1; a < b;) {
                int t = target - nums[a] - nums[b];
                update(a, b, c);
                if (t > nums[c]) { ++a; }
                else if (t < nums[c]) { --b; }
                else {
                    do { ++a; } while (a < b && nums[a] == nums[a - 1]);
                    do { --b; } while (a < b && nums[b] == nums[b + 1]);
                }
            }
            do { --c; } while (c >= 2 && nums[c] == nums[c + 1]);
        }
        return result;
    }
};

TEST(e0100, e0016) {
    vector<int> v = str_to_vect<int>("[-1, 2, 1, -4]");
    ASSERT_EQ(Solution().threeSumClosest(v, 1), 2);
}
