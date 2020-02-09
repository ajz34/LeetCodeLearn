//
// Created by ajz34 on 2020/2/9.
//

#ifndef TWO_SUM
#define TWO_SUM

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec{};
        for (int i = 0; i < nums.size(); ++i)
            for (int j = i + 1; j < nums.size(); ++j)
                if (nums[i] + nums[j] == target)
                    return vector<int>{i, j};
        return vec;
    }
};

#endif