// https://leetcode-cn.com/problems/validate-binary-tree-nodes/

#include "extern.h"

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> father(n, -1);
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1)
                if (father[leftChild[i]] == -1) father[leftChild[i]] = i;
                else return false;
            if (rightChild[i] != -1)
                if (father[rightChild[i]] == -1) father[rightChild[i]] = i;
                else return false;
        }
        int root_count = 0;
        for (auto f : father) {
            if (f == -1) {
                root_count += 1;
                if (root_count >= 2) return false;
            }
        }
        return root_count == 1;
    }
};

TEST(week177, e5170) {
    auto vl = str_to_vec<int>("[1,-1,3,-1]");
    auto vr = str_to_vec<int>("[2,-1,-1,-1]");
    ASSERT_TRUE(Solution().validateBinaryTreeNodes(4, vl, vr));
    vl = str_to_vec<int>("[1,-1,3,-1]");
    vr = str_to_vec<int>("[2,3,-1,-1]");
    ASSERT_FALSE(Solution().validateBinaryTreeNodes(4, vl, vr));
    vl = str_to_vec<int>("[1,0]");
    vr = str_to_vec<int>("[-1,-1]");
    ASSERT_FALSE(Solution().validateBinaryTreeNodes(2, vl, vr));
    vl = str_to_vec<int>("[1,-1,-1,4,-1,-1]");
    vr = str_to_vec<int>("[2,-1,-1,5,-1,-1]");
    ASSERT_FALSE(Solution().validateBinaryTreeNodes(6, vl, vr));
}
