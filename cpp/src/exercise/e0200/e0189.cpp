// https://leetcode-cn.com/problems/rotate-array/

#include "extern.h"

class S0189 {
public:
    int gcd(int v1, int v2) {
        int l = max(v1, v2), r = min(v1, v2);
        while (r != 0) {
            l %= r;
            swap(l, r);
        }
        return l;
    }
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;
        k %= nums.size();
        if (k == 0) return;

        int n_size = nums.size();
        for (int i = 0; i < gcd(nums.size(), k); ++i) {
            int t = nums[i];
            int pl = i, pr = (pl + k) % n_size;
            do {
                swap(nums[pr], t);
                pl = pr;
                pr = (pl + k) % n_size;
            } while (pl != i);
        }
    }
};

TEST(e0200, e0189) {
    vector<int> nums, ans; int k;
    nums = str_to_vec<int>("[1,2,3,4,5,6,7]"), k = 3;
    ans = str_to_vec<int>("[5,6,7,1,2,3,4]");
    S0189().rotate(nums, k);
    ASSERT_THAT(nums, ans);
    nums = str_to_vec<int>("[-1,-100,3,99]"), k = 2;
    ans = str_to_vec<int>("[3,99,-1,-100]");
    S0189().rotate(nums, k);
    ASSERT_THAT(nums, ans);
}
