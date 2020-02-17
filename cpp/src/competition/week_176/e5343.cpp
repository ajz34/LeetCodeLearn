// https://leetcode-cn.com/problems/construct-target-array-with-multiple-sums

#include "extern.h"

class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) return target[0] == 1;     // �����������鳤��ֻ�� 1 �����
        priority_queue<int> heap;                          // ��������
        for (int val : target) {
            if (val <= 0) return false;                    // ���������κ�Ԫ��С����
            heap.push(val);
        }
        long long tmp_sum = 0;
        for (int val : target) tmp_sum += val;              // ��¼ÿ������ĺͣ��� sum(target) ��ʼ��
        while (tmp_sum > target.size()) {                   // ���������Ȼ���� [1, 1, ..., 1]�����������Ȼ�������鳤�ȣ���ѭ��
            int top_val = heap.top(); heap.pop();           // ��¼��������ֵ�����������ֵ
            long long tmp_sum_minus = (tmp_sum - top_val);  // Ʃ�� [5, 9, 17] ��������� tmp_sum_minus = 5 + 9 = 14
            if (top_val <= tmp_sum_minus) return false;     // ������ֵ 17 С�ڻ����Ҫ����ȥ���� 14����ô��������޽��
            long long scaler = ((long long)top_val - heap.top() - 1) / tmp_sum_minus + 1;
            if (top_val - tmp_sum_minus * scaler <= 0) return false;  // This value could be smaller than 0, so we make another check
            heap.push(top_val - tmp_sum_minus * scaler);    // ��Ȼ [5, 9, 17] �н⣬��˰� 17 - 14 * 1 = 3 ���뵽������
            tmp_sum -= tmp_sum_minus * scaler;              // �������ǰ�����͸���һ��
        }
        return true;
    }
};

TEST(week176, e5343) {
    auto v = str_to_vec<int>("[9,3,5]");
    ASSERT_TRUE(Solution().isPossible(v));
    v = str_to_vec<int>("[1,1,1,2]");
    ASSERT_FALSE(Solution().isPossible(v));
    v = str_to_vec<int>("[8,5]");
    ASSERT_TRUE(Solution().isPossible(v));
}

/* �ʼǣ��ü������ƽ���

https://leetcode-cn.com/problems/construct-target-array-with-multiple-sums/solution/yong-jian-fa-dao-tui-jie-ti-by-zhu-zhen-yu-ajz34/

��һ�βμӾ�����������~ ������û������ T-T

������ [9, 17, 5] ���������������ȶ���������õ� [5, 9, 17]
Ȼ������Ӧ�����⵽����� 17 = 9 + 5 + 3��
��ˣ�17 ��ǰ���� 3 = 17 - 9 - 5��
������ǰ�����ĳ� [5, 9, 3]������������õ� [3, 5, 9]����һ�־����� 9���Դ����ơ�
(��������ԭ���ϲ�Ӧ����������ĸ��Ӷ� $O(n \log n)$���������ֻ�ƶ�������������Ӷȿ��Խ��� $O(n)$���öѲ���Ļ������Խ�һ������ $O(\log n)$)

�ɹ����о��ǣ�����������ȫ�� 1 (������ĺ������鳤�� 3)��
ʧ�ܵ��о����κ�һ���������� 0 ������Ʃ�� [1, 1, 1, 2] ������ͨ������Ĺ��̻�õ� [1, 1, 1, -1]��
��ˣ��������˼·�������㷨�ĸ��Ӷ���õ�������� $O(T \log n + n \log n)$������ $T$ �ǿ����ĵ���������
(�����������ʱ�ύ�Ĵ��뻹�� $O(T n \log n + n \log n)$)

�Դ����ƾ��ܽ������~
������
- `tmp_sum` �ǵ�ǰ������ĺͣ����� [5, 9, 17] ������ 31��
- `tmp_sum_minus` ����Ҫ����ȥ�����ĺͣ����� [5, 9, 17] ������ 14��
- `scaler` ����Ҫ���������ı������������ [5, 9, 31] ���ԣ�31 - 14 = 17 �������������˲���ɴ� 31 - 14 * 2 = 9������ `scaler = 2`������Ա����������������� `[1000000000, 1]` ʱ������ĳ�ʱ��(����� [LightT](https://leetcode-cn.com/problems/construct-target-array-with-multiple-sums/comments/243999) ������) ��ˣ��ڼ��� `scaler` �����󣬿����ĵ������� $T$ Ӧ��������� $n$��
- ��л [@����](https://leetcode-cn.com/problems/construct-target-array-with-multiple-sums/solution/yong-jian-fa-dao-tui-jie-ti-by-zhu-zhen-yu-ajz34/244737) ָ�������⡣��������ͨ���������ݣ��� `scaler` ��Ȼ�п���д�ò��ԡ������ϸ�İ취Ӧ������ȡ���Ƿ�Ϊ���жϣ������������ܲ�����һЩС���ɱ���ȡ��Ĵ��� =��=

�����������ͺ� int ������������� long long��

**�����Ż��Ĵ���** $O(T \log n + n \log n)$ 60ms����Ҫ����������� (��)

```c++
class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) return target[0] == 1;     // �����������鳤��ֻ�� 1 �����
        priority_queue<int> heap;                          // ��������
        for (int val : target) {
            if (val <= 0) return false;                    // ���������κ�Ԫ��С����
            heap.push(val);
        }
        long long tmp_sum = 0;
        for (int val : target) tmp_sum += val;              // ��¼ÿ������ĺͣ��� sum(target) ��ʼ��
        while (tmp_sum > target.size()) {                   // ���������Ȼ���� [1, 1, ..., 1]�����������Ȼ�������鳤�ȣ���ѭ��
            int top_val = heap.top(); heap.pop();           // ��¼��������ֵ�����������ֵ
            long long tmp_sum_minus = (tmp_sum - top_val);  // Ʃ�� [5, 9, 17] ��������� tmp_sum_minus = 5 + 9 = 14
            if (top_val <= tmp_sum_minus) return false;     // ������ֵ 17 С�ڻ����Ҫ����ȥ���� 14����ô��������޽��
            long long scaler = ((long long)top_val - heap.top() - 1) / tmp_sum_minus + 1;  // Additional thanks to comment from @����
            if (top_val - tmp_sum_minus * scaler <= 0) return false;  // This value could be smaller than 0, so we make another check
            heap.push(top_val - tmp_sum_minus * scaler);    // ��Ȼ [5, 9, 17] �н⣬��˰� 17 - 14 * 1 = 3 ���뵽������
            tmp_sum -= tmp_sum_minus * scaler;              // �������ǰ�����͸���һ��
        }
        return true;
    }
};
```

**����ύ�ģ����ĵ������ƵĴ���** $O(T n \log n + n \log n)$ ~180ms������Ҫ��������������� `[1000000000, 1]` �������»ᳬʱ

```c++
class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) return target[0] == 1;
        if (target[0] <= 0) return false;
        sort(target.begin(), target.end());
        long long tmp_sum = 0; for (int val : target) tmp_sum += val;
        while (tmp_sum > target.size()) {
            int idx_last = int(target.size()) - 1;
            long long tmp_sum_minus = (tmp_sum - target[idx_last]);
            if (target[idx_last] < tmp_sum_minus) return false;
            target[idx_last] -= tmp_sum_minus;
            tmp_sum -= tmp_sum_minus;
            sort(target.begin(), target.end());
        }
        return true;
    }
};
```

*/