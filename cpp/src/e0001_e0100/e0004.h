//
// Created by ajz34 on 2020/2/10.
//

#ifndef E0004_ARRAY_MEDIAN_H
#define E0004_ARRAY_MEDIAN_H

#include <vector>
#include <algorithm>
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

#endif //TEST_CPP_E0004_ARRAY_MEDIAN_H
