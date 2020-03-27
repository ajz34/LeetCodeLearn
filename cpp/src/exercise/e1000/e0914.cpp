// https://leetcode-cn.com/problems/x-of-a-kind-in-a-deck-of-cards/

#include "extern.h"

class S0914 {
    int gcd(int m, int n) {
        if (m < n) swap(m, n);
        while (n != 0) {
            m %= n;
            swap(m, n);
        }
        return m;
    }
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mp;
        for (auto i : deck) mp[i] += 1;
        int g = -1;
        if (mp.size() > 1) {
            g = mp.begin()->second;
            for (auto& p : mp) {
                if (p.second % g != 0)
                    g = gcd(p.second, g);
                if (g == 1) return false;
            }
            return true;
        }
        else if (mp.size() == 1)
            return mp.begin()->second > 1;
        else return false;
    }
};

TEST(e1000, e0914) {
    vector<int> deck;
    deck = str_to_vec<int>("[1,2,3,4,4,3,2,1]");
    ASSERT_TRUE(S0914().hasGroupsSizeX(deck));
    deck = str_to_vec<int>("[1,1,1,2,2,2,3,3]");
    ASSERT_FALSE(S0914().hasGroupsSizeX(deck));
    deck = str_to_vec<int>("[1]");
    ASSERT_FALSE(S0914().hasGroupsSizeX(deck));
    deck = str_to_vec<int>("[1,1]");
    ASSERT_TRUE(S0914().hasGroupsSizeX(deck));
    deck = str_to_vec<int>("[1,1,2,2,2,2]");
    ASSERT_TRUE(S0914().hasGroupsSizeX(deck));
}
