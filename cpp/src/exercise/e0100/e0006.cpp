#include "extern.h"

class Solution {
public:
    string convert(string s, int numRows) {
        // let n = numRows, N = 2n - 2
        // row i: i, N - i, N + i, 2N - i, ...
        if (s.empty()) return "";
        if (numRows == 1) return s;
        string r;
        int n = numRows; int N = 2 * n - 2; int size = s.size();
        for (int i = 0; i < n; ++i) {
            int m = 0;
            while (true) {
                if (m * N + i < size)
                    r.push_back(s[m * N + i]);
                else break;
                ++m;
                if (i == 0 || i == n - 1) continue;
                if (m * N - i < size)
                    r.push_back((s[m * N - i]));
                else break;
            }
        }
        return r;
    }
};

TEST(e0100, e0006) {
    ASSERT_EQ(Solution().convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
    ASSERT_EQ(Solution().convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
    ASSERT_EQ(Solution().convert("A", 1), "A");
}
