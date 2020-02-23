// https://leetcode-cn.com/problems/sort-integers-by-the-number-of-1-bits/

#include "extern.h"

class Solution {
    struct BitsCompare {
        inline bool operator()(pair<int, int>& p1, pair<int, int>& p2) {
            if (p2.second != p1.second) return p1.second < p2.second;
            else return p1.first < p2.first;
        }
    };
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> digits;
        for (int w : arr) {
            int v = w;
            int n = 0;
            while (v > 0) {
                if (v % 2 != 0) ++n;
                v /= 2;
            }
            digits.push_back(make_pair(w, n));
        }
        sort(digits.begin(), digits.end(), BitsCompare());
        vector<int> results;
        for (auto p : digits) results.push_back(p.first);
        return results;
    }
};

TEST(double20, e5323) {
    vector<int> arr, ans;
    arr = str_to_vec<int>("[0,1,2,3,4,5,6,7,8]");
    ans = str_to_vec<int>("[0,1,2,4,8,3,5,6,7]");
    ASSERT_THAT(Solution().sortByBits(arr), ans);
    arr = str_to_vec<int>("[1024,512,256,128,64,32,16,8,4,2,1]");
    ans = str_to_vec<int>("[1,2,4,8,16,32,64,128,256,512,1024]");
    ASSERT_THAT(Solution().sortByBits(arr), ans);
    arr = str_to_vec<int>("[10000,10000]");
    ans = str_to_vec<int>("[10000,10000]");
    ASSERT_THAT(Solution().sortByBits(arr), ans);
    arr = str_to_vec<int>("[2,3,5,7,11,13,17,19]");
    ans = str_to_vec<int>("[2,3,5,17,7,11,13,19]");
    ASSERT_THAT(Solution().sortByBits(arr), ans);
    arr = str_to_vec<int>("[10,100,1000,10000]");
    ans = str_to_vec<int>("[10,100,10000,1000]");
    ASSERT_THAT(Solution().sortByBits(arr), ans);
}
