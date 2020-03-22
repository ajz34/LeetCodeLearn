// https://leetcode-cn.com/problems/four-divisors/

#include "extern.h"

class S5178 {
public:
    set<int> prime_vec;
    void gen_prime_set() {
        set<int> st;
        for (int i = 2; i < 100010; ++i)
            st.insert(i);
        while (!st.empty()) {
            int p = *st.begin();
            prime_vec.insert(p);
            int v = p;
            while (!st.empty() && v <= *prev(st.end())) {
                st.erase(v);
                v += p;
            }
        }
    }
    S5178() {
        gen_prime_set();
    }
    int sumFourDivisorsInner(int v) {
        int sqrv = int(sqrt(v));
        for (int d : prime_vec) {
            if (d > sqrv) break;
            if (v % d == 0) {
                if ((prime_vec.find(v / d) != prime_vec.end() && (v / d != d)) || ((v / d) % d == 0 && v / d / d == d))
                    return 1 + v + d + v / d;
                else return 0;
            }
        }
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        for (int n : nums)
            result += sumFourDivisorsInner(n);
        return result;
    }
};

TEST(week181, e5178) {
    vector<int> nums;
    nums = str_to_vec<int>("[21,4,7]");
    ASSERT_EQ(S5178().sumFourDivisors(nums), 32);
}
