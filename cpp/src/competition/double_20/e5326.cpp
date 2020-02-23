// https://leetcode-cn.com/problems/count-all-valid-pickup-and-delivery-options/

#include "extern.h"

class Solution {
public:
    int countOrders(int n) {
        auto mult_mod = [](long long a1, long long a2) { return (a1 * a2) % 1000000007; };
        long long p = 1;
        for (int i = 1; i <= n; ++i)
            p = mult_mod(p, (2 * i - 1) * i);
        return int(p);
    }
};

TEST(double20, e5326) {
    ASSERT_EQ(Solution().countOrders(1), 1);
    ASSERT_EQ(Solution().countOrders(2), 6);
    ASSERT_EQ(Solution().countOrders(3), 90);
}

/* ��⣺https://leetcode-cn.com/problems/count-all-valid-pickup-and-delivery-options/solution/shu-xue-gui-na-fa-qiu-jie-by-zhu-zhen-yu-ajz34/

��ʵ�� 4 ���ƺ���һ����ѧ���ɷ��� hh

## ������ʽ

Ʃ��˵������������ $n$ ����Ӧ��������Ŀ����Ϊ $p(n)$����ô������ʽ�� (��л [@jartus](https://leetcode-cn.com/problems/count-all-valid-pickup-and-delivery-options/solution/shu-xue-gui-na-fa-qiu-jie-by-zhu-zhen-yu-ajz34/252615) ָ��)

$$
p(n) = p(n - 1) \times (C_{2n-1}^2 + 2 n - 1) = p(n - 1) \times \left( (2 n - 1) n \right)
$$

������ʼ���������� $p(1) = 1$��Ҳ������ $p(0) = 1$��

������������ʽ����Դ����ô�������ڿ��� $n = 4$ ��������� $p(n) = 2520$����������Ҫ������ 4 �������еĶ����У����������ֲ��뷽��������һ�������ǣ�
```
 O O O O O O
|     |
```
���� 4 �������ķַ��������ֱ�Ĺ��̣��൱���� $(2 \times 3 + 1) = (2 \times 4 - 1) = 7$ ������ڲ�������������ֲ��뷽���ܹ��� $C_7^2 = 21$ �ֿ����ԡ��ٸ���ԭ�� 1-3 �����ĸ��ֿ���������������� $p(4)$ �Ĺ����� $p(3) \times C_{2 \times 4 - 1}^2 = 90 \times 21 = 1890$��

��һ�������ǣ�
```
  O  O  O  O  O  O
      ||
```
���� 4 �������ķַ���һ���൱���� $7$ ������ڲ�һ������˲��뷽���� $C_7^1 = 7$ �ֿ����ԡ���ˣ�������� $p(4)$ �Ĺ����� $p(3) \times 7 = 90 \times 7 = 630$��

������ǾͿ��Եõ� $p(4) = 1890 + 630 = 2520$ �������������֤����������ᵽ�ĵ�����ʽ��ȷʵ�ܵõ� $p(4) = p(3) \times (7 \times 4) = 2520$����������������Ϳ������ơ�

## ���ڴ���ͬ��

���ڽ����ֵ�ǳ��������Ҫ����ͬ����㡣

���ȣ��������м�����о���ʹ�� `long long` �������������ͣ����� 10^9 ���������� 10^2 �����ĳ˷����¶����������

��Σ����������������ۡ��������� $a = k \times b + t$������ $0 \leqslant t < b$��$0 \leqslant k$ ����������Ϊ�Ǹ������� `(a % b) = t`����ô

$$
a_1 a_2 = (k_1 k_2 b + k_1 t_2 + k_2 t_1) \times b + t_1 t_2
$$

�� `(a1 * a2) % b = (t_1 * t_2) % b`������˵�ǳ˷���ģ����������ģ��ȡ�

��������ĺ��� `mult_mod` �������� `a1, a2`�����ص� `b = 10^9 + 7` �µĳ˷����ģ����

## ����

```c++
class Solution {
public:
    int countOrders(int n) {
        auto mult_mod = [](long long a1, long long a2) { return (a1 * a2) % 1000000007; };
        long long p = 1;
        for (int i = 1; i <= n; ++i)
            p = mult_mod(p, (2 * i - 1) * i);
        return int(p);
    }
};
```


*/
