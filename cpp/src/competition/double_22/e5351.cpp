// https://leetcode-cn.com/problems/pizza-with-3n-slices/

#include "extern.h"

class S5351 {
    // ��� n-1 �������� slices �ָ��У�ȡ������������ (n-1)/3 + 1 ����������������ܺ�
    // �� n = 11, ��ôȡ�������������� 4 ��
    int maxSizeSlicesInner(vector<int>& slices) {
        vector<vector<int>> dp(slices.size() / 3 + 1, vector<int>(slices.size(), 0));
        dp[0] = slices;
        for (int r = 1; r < dp.size(); ++r) {
            int prev_max = 0;  // ��ʾ�� [0, 0], [0, 1], ..., [0, c-2] ����������ȡ�������� r �������������£���������ܺ͵����ֵ
            for (int c = 0; c < slices.size(); ++c) {
                if (c >= 2) prev_max = max(dp[r - 1][c - 2], prev_max);
                dp[r][c] = slices[c] + prev_max;  // dp[r][c] ��ʾ [0, c] �����������ȡ�������� r + 1 �� (������ c ��) �����������£���������ܺ�
            }
        }
        return *max_element(dp.back().begin(), dp.back().end());  // �𰸼��� dp �����һ�е����ֵ
    }
    int maxSizeSlicesInnerLinear(vector<int>& slices) {
        vector<int> dp_prev(slices);
        vector<int> dp_next(slices.size(), 0);
        int n = slices.size() / 3 + 1;
        for (int r = 1; r < n; ++r) {
            int prev_max = 0;
            for (int c = 0; c < slices.size(); ++c) {
                if (c >= 2) prev_max = max(dp_prev[c - 2], prev_max);
                dp_next[c] = slices[c] + prev_max;
            }
            swap(dp_prev, dp_next);
        }
        return *max_element(dp_prev.begin(), dp_prev.end());
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        vector<int> v1(slices.begin() + 1, slices.end());    // ȥ����һ������������
        vector<int> v2(slices.begin(), prev(slices.end()));  // ȥ�����һ������������
        return max(maxSizeSlicesInner(v1), maxSizeSlicesInner(v2));  // ȡ�������ε����ֵ
    }
};

TEST(double22, e5351) {
    vector<int> slices;
    slices = str_to_vec<int>("[1,2,3,4,5,6]");
    ASSERT_EQ(S5351().maxSizeSlices(slices), 10);
    slices = str_to_vec<int>("[8,9,8,6,1,1]");
    ASSERT_EQ(S5351().maxSizeSlices(slices), 16);
    slices = str_to_vec<int>("[4,1,2,5,8,3,1,9,7]");
    ASSERT_EQ(S5351().maxSizeSlices(slices), 21);
    slices = str_to_vec<int>("[3,1,2]");
    ASSERT_EQ(S5351().maxSizeSlices(slices), 3);
}

/* ������⣺��Ϊ�����ڵ������е��������⣬��̬�滮
   https://leetcode-cn.com/problems/pizza-with-3n-slices/solution/hua-wei-bu-xiang-lin-de-zi-shu-lie-de-zui-da-he-we/
*/
