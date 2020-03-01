// https://leetcode-cn.com/problems/how-many-numbers-are-smaller-than-the-current-number/

#include "extern.h"

class S5344 {
    struct ComparePair {
        inline bool operator()(pair<int, int>& p1, pair<int, int>& p2) {
            return p1.first < p2.first;
        }
    };
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<pair<int, int>> num_pair;
        for (int i = 0; i < nums.size(); ++i) num_pair.push_back(make_pair(nums[i], i));
        sort(num_pair.begin(), num_pair.end(), ComparePair());
        vector<int> result(nums.size(), 0);
        int cur_idx = 0; int cur_num = result.front() == 0 ? 1 : 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (num_pair[i].first != cur_num) {
                cur_num = num_pair[i].first;
                cur_idx = i;
            }
            result[num_pair[i].second] = cur_idx;
        }
        return result;
    }
};

TEST(week178, e5344) {
    vector<int> nums, ans;
    nums = str_to_vec<int>("[8,1,2,2,3]");
    ans = str_to_vec<int>("[4,0,1,1,3]");
    ASSERT_THAT(S5344().smallerNumbersThanCurrent(nums), ans);
    nums = str_to_vec<int>("[6,5,4,8]");
    ans = str_to_vec<int>("[2,1,0,3]");
    ASSERT_THAT(S5344().smallerNumbersThanCurrent(nums), ans);
    nums = str_to_vec<int>("[7,7,7,7]");
    ans = str_to_vec<int>("[0,0,0,0]");
    ASSERT_THAT(S5344().smallerNumbersThanCurrent(nums), ans);
}
