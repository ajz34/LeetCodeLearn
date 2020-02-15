//
// Created by ajz34 on 2020/2/11.
//

#ifndef E0015_THREE_SUM_H
#define E0015_THREE_SUM_H

#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // https://leetcode-cn.com/problems/3sum/comments/16475 Strictly O(n^2)
        vector<vector<int>> result{};
        if (nums.empty()) return result;
        sort(nums.begin(), nums.end());
        for (size_t c = nums.size() - 1; c >= 2;) {
            for (size_t a = 0, b = c - 1; a < b;) {
                int t = nums[a] + nums[b];
                if (t < -nums[c]) ++a;
                else if (t > -nums[c]) --b;
                else {
                    result.push_back({nums[a], nums[b], nums[c]});
                    do { ++a; } while (a < b && nums[a] == nums[a - 1]);
                    do { --b; } while (a < b && nums[b] == nums[b + 1]);
                }
            }
            do { --c; } while (c >= 2 && nums[c] == nums[c + 1]);
        }
        return result;
    }

    vector<vector<int>> threeSum_n2logn(vector<int>& nums) {
        vector<vector<int>> result{};
        if (nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        // first exclude impossible situations, so we can make some assertions on size of `nums`
        if (nums.front() > 0 || nums.back() < 0) return result;
        // then three sum: O(n^2 log(n))
        // >>>i ... -2, -1 0 || 1, 2, ... j<<<;
        // let k impose k + i + j = 0
        // k should be between i and j
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) break;
            if (nums[i] == 0 && i + 2 < nums.size() && nums[i + 2] == 0) {
                result.push_back({0, 0, 0});  // include situation that 0 + 0 + 0 = 0
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // exclude situation that make duplicate triples
            for (size_t j = nums.size(); j-- > 0;) {
                if (nums[j] <= 0) break;
                if (j < nums.size() - 1 && nums[j] == nums[j + 1]) continue;  // exclude situation that make duplicate triples
                int vk = -(nums[i] + nums[j]);
                if (vk < nums[i]) continue;  // j search continues if k < i < j
                if (vk > nums[j]) break;     // j search breaks    if i < j < k, means i should be updated
                if (!binary_search(&nums[i], &nums[j], vk)) continue;  // search whether k exists between i and j
                if (vk == nums[i] && nums[i + 1] != vk) continue;      // exclude k = i < j, but i only occurs once
                if (vk == nums[j] && nums[j - 1] != vk) break;         // exclude i < k = j, but j only occurs once
                result.push_back({nums[i], vk, nums[j]});
            }
        }
        return result;
    }

    vector<vector<int>> threeSum_slow(vector<int>& nums) {
        // find occurrences of values, store to map <number, occurrence>
        vector<vector<int>> result{};
        map<int, int> mp{};
        for (int n : nums) {
            auto p = mp.find(n);
            if (p == mp.cend()) mp[n] = 1;
            else p->second += 1;
        }
        vector<pair<int, int>> vp{}; vp.reserve(mp.size());
        for (auto i : mp) vp.emplace_back(i);
        // three sum
        // -2, -1 :pi <<< 0 >>> pj: 1, 2, ...;
        // let vk impose vk + pi.value + pj.value = 0
        for (auto pi = vp.cbegin(); pi != vp.cend(); ++pi) {
            if (pi->first == 0) {
                // special situation of three zeros
                if (pi->second >= 3) result.push_back({0, 0, 0});
                break;
            }
            else if (pi->first > 0) break;
            else for (auto pj = vp.crbegin(); pj != vp.crend(); ++pj) {
                if (pj->first < 0) break;
                int vk = -(pi->first + pj->first);
                if (mp.find(vk) == mp.cend()) continue;
                if (vk < pi->first) continue; if (vk > pj->first) break;
                if (vk == pi->first && pi->second == 1) continue;
                if (vk == pj->first && pj->second == 1) break;
                result.push_back({pi->first, vk, pj->first});
            }
        }
        return result;
    }
};

#endif //TEST_CPP_E0015_THREE_SUM_H
