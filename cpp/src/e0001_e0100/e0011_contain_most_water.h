//
// Created by ajz34 on 2020/2/11.
//

#ifndef E0011_CONTAIN_MOST_WATER_H
#define E0011_CONTAIN_MOST_WATER_H

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // worst case O(n^2), but first find a slope,
        // containing mono up then down series of numbers
        vector<pair<int, int>> vf{pair<int, int>{0, height[0]}};
        vector<pair<int, int>> vb{pair<int, int>{height.size() - 1, height.back()}};
        vf.reserve(height.size()); vb.reserve(height.size());
        for (size_t i = 1; i < height.size(); ++i)
            if (height[i] >= vf.back().second) vf.emplace_back(pair<int, int>{i, height[i]});
        for (size_t i = height.size() - 1; i-- > 0;)
            if (height[i] >= vb.back().second) vb.emplace_back(pair<int, int>{i, height[i]});
        // naive O(n^2)
        int max_area = 0;
        for (auto & i : vf)
            for (auto & j : vb) {
                if (j.first < i.first) break;
                max_area = max(min(i.second, j.second) * (j.first - i.first), max_area);
            }
        return max_area;
    }

    int maxArea_slow(vector<int>& height) {
        int max_area = 0;
        for (int i = 0; i < height.size(); ++i)
            for (int j = i + 1; j < height.size(); ++j)
                max_area = max(min(height[i], height[j]) * (j - i), max_area);
        return max_area;
    }
};

#endif //TEST_CPP_E0011_CONTAIN_MOST_WATER_H
