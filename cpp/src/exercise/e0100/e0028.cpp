#include "extern.h"

// KMP Algorithm: http://www.btechsmartclass.com/data_structures/knuth-morris-pratt-algorithm.html

class Solution {
public:
    int strStr(string haystack, string needle) {
        // 0. Exclude empty needle situation and smaller haystack situation
        if (needle.empty()) return 0;
        if (haystack.size() < needle.size()) return -1;
        // 1. Create LPS table
        //    Make sure that from lps[1], value of lps[i] refers to same string length from front of needle
        // A B C D A B D ==> j
        // 0 0 0 0 1 2 0 ==> i
        // A A B A A A C   Fifth A: (i, j) : (1, 4) -> situ.1 (2, 5) -> situ.2 (1, 5) -> situ.1 (2, 6)
        // 0 1 0 1 2 2 0               lps :           lps[4] = 2                        lps[5] = 2
        vector<size_t> lps(needle.size(), 0);
        size_t i = 0, j = 1;
        while (j < needle.size()) {
            if (needle[i] == needle[j]) lps[j++] = (i++) + 1;  // situ.1
            else if (i != 0) i = lps[i - 1];                   // situ.2
            else lps[j++] = 0;                                 // situ.3
        }
        // 2. Loop the LPS table
        //    situation 1: A B C D A B   A B C D  ph = 0  -->  n - lps[n - 1] = 6 - lps[5] = 6 - 2 = 4
        //                 A B C D A B D          n = 6   -->  lps[n] = idx[5] = 2
        //             ==>         A B C D A B D  next compare ph + n = 6
        //    situation 2: E E E E E E E          ph = 0  -->  ph + 1 = 1
        //                 A B C D A B D          n = 0   -->  lps[n] = 0
        //             ==>   A B C D A B D        next compare ph + n = 1
        auto ph = haystack.cbegin(); size_t n = 0;
        while (ph + n - haystack.cend() < 0) {
            if (*(ph + n) != needle[n]) {
                ph += n == 0 ? 1 : n - lps[n - 1];
                n = n == 0 ? 0 : lps[n - 1];
            }
            else if (n == needle.size() - 1) return int(ph - haystack.cbegin());
            else ++n;
        }
        return -1;
    }
};

TEST(e0100, e0028) {
    ASSERT_EQ(Solution().strStr("ABC ABCDAB ABCDABCDABDE", "ABCDABD"), 15);
    ASSERT_EQ(Solution().strStr("hello", "ll"), 2);
    ASSERT_EQ(Solution().strStr("aaaaa", "bba"), -1);
    ASSERT_EQ(Solution().strStr("aabaaabaaac", "aabaaac"), 4);
}
