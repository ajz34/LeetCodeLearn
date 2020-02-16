#include "extern.h"

// TODO: Algorithm is considered as O(n2 log(n)), but its efficiency is far less than naive two-pointer O(n3)
//       Should review this case later

template<class T, class U>
class ComparePair {
public:
    // Compare pair only by its first value
    inline bool operator()(const pair<T, U>& p1, const pair<T, U>& p2) {
        return p1.first < p2.first;
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // 0. Exclude situation that nums.size() is smaller than required
        if (nums.size() <= 3) return vector<vector<int>>{};
        // 1. Sort array, O(n log(n))
        sort(nums.begin(), nums.end());
        // 2. Make repeat index, will be used to remove same sequence occurrence, O(n)
        // things like
        //                  0 1 1 2 3 4 4 5
        // original index:  0 1 2 3 4 5 6 7
        // nums_rp       :  0 1 1 3 4 5 5 7
        vector<size_t> nums_rp(nums.size(), 0);
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) nums_rp[i] = nums_rp[i - 1];
            else nums_rp[i] = i;
        }
        // 3. Add every two numbers into map `twosum`, O(n2 log(n2)) = O(n2 log(n))
        // key: the sum of every two numbers; value: two numbers original index
        // Originally it was implemented by map, but then changed to vector with sort, avoiding insertion to map
        vector<pair<int, pair<size_t, size_t>>> twosum{};
        for (size_t i = 0; i < nums.size(); ++i)
            for (size_t j = i + 1; j < nums.size(); ++j)
                twosum.push_back(make_pair(nums[i] + nums[j], make_pair(i, j)));
        sort(twosum.begin(), twosum.end(), ComparePair<int, pair<size_t, size_t>>());
        // 4.1. Generate unique 4-number index
        auto unique = [&nums](const vector<size_t> & idx) {
            return ((idx[0] * nums.size() + idx[1]) * nums.size() + idx[2]) * nums.size() + idx[3];
        };
        // 4.2 Update redundent-included results into `result_vec`
        // key: unique index 4-number index; value: 4-number as result
        vector<pair<size_t, vector<int>>> result_vec{};
        vector<size_t> idx(4, 0);
        // l, r is the 2-number pair index
        // l.first = a, l.right = b, r.left = c, r.right = d
        // assert that nums[a] + nums[b] + nums[c] + nums[d] = target when calling this lambda function
        auto update = [&nums, &idx, &unique, &nums_rp, &result_vec](const pair<size_t, size_t>& l, const pair<size_t, size_t>& r) {
            if (l.second >= r.first) return;  // exclude situation that is not nums[a] < nums[b] < nums[c] < nums[d]
            idx[0] = nums_rp[l.first]; idx[1] = nums_rp[l.second]; idx[2] = nums_rp[r.first]; idx[3] = nums_rp[r.second];
            result_vec.push_back(make_pair(unique(idx), vector<int>{ nums[idx[0]], nums[idx[1]], nums[idx[2]], nums[idx[3]] }));
        };
        // 4. Find all occurrences of 4-numbers, average: O(n2), worst: O(n4)
        // we have the 2-number sum map `twosum`
        // then we use two-pointer method to find situation that (summation of two 2-number sum == target 4-sum)
        //   suppose now (a + b + c + d = 10) and (a + b = 4), (c + d = 6)
        //   however, cases (1, 2, 3) satisfy (a + b = 4), and cases (8, 9) satisfy (c + d = 6)
        //   we find `pll` = 4, `prr` = 9, then try to find `plr` and `prl`:
        //   then case   0   1   2   3   4   5   6   7   8   9   10   11 ...
        //                 pll         plr         prl     prr
        //   we try to update all possible situations (18, 28, 38, 19, 29, 39), then move `pll` to right, and move `prr` to left
        vector<pair<int, pair<size_t, size_t>>>::const_iterator pll, prr, plr, prl;
        pll = twosum.cbegin(); prr = prev(twosum.cend());
        while (pll != twosum.cend() && prr != twosum.cbegin() && pll->first <= prr->first) {
            if (pll->first + prr->first < target) ++pll;
            else if (pll->first + prr->first > target) --prr;
            else {
                plr = pll; prl = prr;
                do { ++plr; } while (plr != twosum.cend() && plr->first == pll->first);
                do { --prl; } while (prl != twosum.cbegin() && prl->first == prr->first);
                for (auto pl = pll; pl != plr; ++pl)
                    for (auto pr = prr; pr != prl; --pr)
                        update(pl->second, pr->second);
                pll = plr; prr = prl;
            }
        }
        // 5. Sort and exclude same occurences from `result_vec`
        // O(t log(t)) where (t = result.size()), worst case O(n4 log(n)), average unknown
        sort(result_vec.begin(), result_vec.end(), ComparePair<size_t, vector<int>>());
        vector<vector<int>> result{};
        for (size_t i = 0; i < result_vec.size(); ++i)
            if (i == 0 || result_vec[i].first != result_vec[i - 1].first) result.emplace_back(result_vec[i].second);
        return result;
    }
};

TEST(e0100, e0018) {
    vector<int> v = str_to_vect<int>("[1, 0, -1, 0, -2, 2]");
    vector<vector<int>> res_vector = Solution().fourSum(v, 0);
    vector<vector<int>> ans_vector = str_to_mat<int>(
    "[                  \
        [-1, 0, 0, 1],  \
        [-2, -1, 1, 2], \
        [-2, 0, 0, 2]   \
    ]");
    set<vector<int>> res{ res_vector.begin(), res_vector.end() };
    set<vector<int>> ans{ ans_vector.begin(), ans_vector.end() };
    ASSERT_THAT(res, ans);
}
