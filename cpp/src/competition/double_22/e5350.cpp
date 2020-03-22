// https://leetcode-cn.com/problems/sort-integers-by-the-power-value/

#include "extern.h"

class S5350 {
    int getWeight(int v) {
        int result = 0;
        while (v != 1) {
            if (v % 2 == 0) v /= 2;
            else v = 3 * v + 1;
            ++result;
        }
        return result;
    }
    struct ComparePair {
        inline bool operator()(pair<int, int> p1, pair<int, int> p2) {
            if (p1.second != p2.second) return p1.second < p2.second;
            else return p1 < p2;
        }
    };
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> vec;
        for (int i = lo; i <= hi; ++i)
            vec.push_back({ i, getWeight(i) });
        sort(vec.begin(), vec.end(), ComparePair());
        return vec[k - 1].first;
    }
};

TEST(double22, e5350) {
    ASSERT_EQ(S5350().getKth(12, 15, 2), 13);
    ASSERT_EQ(S5350().getKth(1, 1, 1), 1);
    ASSERT_EQ(S5350().getKth(7, 11, 4), 7);
    ASSERT_EQ(S5350().getKth(10, 20, 5), 13);
    ASSERT_EQ(S5350().getKth(1, 1000, 777), 570);
}
