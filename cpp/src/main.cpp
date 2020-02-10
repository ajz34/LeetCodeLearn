//
// Created by ajz34 on 2020/2/9.
//

#include "e0001_e0100/e0004_array_median.h"

#include <iostream>
using namespace std;

int main() {
    vector<int> nums1 {1, 3};
    vector<int> nums2 {2};
    cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
}