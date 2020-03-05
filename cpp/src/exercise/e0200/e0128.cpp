// https://leetcode-cn.com/problems/longest-consecutive-sequence/

#include "extern.h"

class S0128 {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> table{ nums.begin(), nums.end() };
        int result = 1;
        while (!table.empty()) {
            int cnt = 1;
            int orig = *table.begin();
            table.erase(orig);
            int val = orig;
            while (true) {
                val += 1;
                if (table.find(val) == table.end()) break;
                table.erase(val);
                cnt += 1;
            }
            val = orig;
            while (true) {
                val -= 1;
                if (table.find(val) == table.end()) break;
                table.erase(val);
                cnt += 1;
            }
            result = max(result, cnt);
        }
        return result;
    }
};

TEST(e0200, e0128) {
    vector<int> nums;
    nums = str_to_vec<int>("[100, 4, 200, 1, 3, 2]");
    ASSERT_EQ(S0128().longestConsecutive(nums), 4);
}
