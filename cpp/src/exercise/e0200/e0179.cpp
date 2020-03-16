// https://leetcode-cn.com/problems/largest-number/

#include "extern.h"

class S0179 {
    struct StringCompare {
        inline bool operator()(string& s1, string& s2) {
            return s1 + s2 > s2 + s1;
        }
    };
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) return "";
        if (*max_element(nums.begin(), nums.end()) == 0) return "0";
        vector<string> vec;
        for (auto n : nums) vec.push_back(to_string(n));
        sort(vec.begin(), vec.end(), StringCompare());
        string result;
        for (auto& s : vec) result += s;
        return result;
    }
};

TEST(e0200, e0179) {
    vector<int> nums;
    nums = str_to_vec<int>("[10,2]");
    ASSERT_EQ(S0179().largestNumber(nums), "210");
    nums = str_to_vec<int>("[3,30,34,5,9]");
    ASSERT_EQ(S0179().largestNumber(nums), "9534330");
}
