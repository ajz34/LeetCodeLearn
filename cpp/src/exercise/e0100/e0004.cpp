#include "extern.h"
using namespace std;

class Solution {
public:
    double findMedianSortedArrays_slow(vector<int>& nums1, vector<int>& nums2) {
        auto v = vector<int>();
        v.insert(v.end(), nums1.cbegin(), nums1.cend());
        v.insert(v.end(), nums2.cbegin(), nums2.cend());
        sort(v.begin(), v.end());
        if (v.size() % 2 == 1) return v[v.size() / 2];
        else return double(v[(v.size() + 1) / 2] + v[(v.size() - 1) / 2]) / 2;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t s = nums1.size() + nums2.size();
        auto v = vector<int>(s, 0);
        auto p1 = nums1.cbegin(); auto p2 = nums2.cbegin(); auto pt = v.begin();
        size_t t = 0;
        while (p1 != nums1.cend() && p2 != nums2.cend()) {
            if (*p1 > *p2) { *pt = *p2; ++p2; }
            else { *pt = *p1; ++p1; }
            ++pt;
        }
        while (p1 != nums1.cend()) { *pt = *p1; ++p1; ++pt; }
        while (p2 != nums2.cend()) { *pt = *p2; ++p2; ++pt; }

        if (s % 2 == 1) return v[s / 2];
        else return double(v[(s + 1) / 2] + v[(s - 1) / 2]) / 2;
    }
};

TEST(e0100, e0004) {
    vector<int> n1{}, n2{};
    n1 = str_to_vec<int>("[1, 3]");
    n2 = str_to_vec<int>("[2]");
    ASSERT_EQ(Solution().findMedianSortedArrays(n1, n2), 2);
    n1 = str_to_vec<int>("[1, 2]");
    n2 = str_to_vec<int>("[3, 4]");
    ASSERT_EQ(Solution().findMedianSortedArrays(n1, n2), 2.5);
}
