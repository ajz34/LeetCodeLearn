// https://leetcode-cn.com/problems/divide-two-integers/

#include "extern.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
        // 0. �ų��󲿷ּ������
        //    ����Ҫע�⣬����û���ų�������� dividend = -2147483648 �� divisor != (+/-) 1
        if (divisor == 1) return dividend;
        else if (divisor == -1) return (dividend == -2147483648) ? 2147483647 : -dividend;
        // 1. ��ȡ������ֵ�ķ���
        bool sgn = (dividend > 0 == divisor > 0);
        // 2. ���������ĸ��ȡΪ��ֵ (������� dividend = 2147483648)
        if (dividend > 0) dividend = -dividend;
        if (divisor > 0) divisor = -divisor;
        // 3. ���������飬��һ���� ��ĸ * 2^n��������� 2^n
        //    ���ϣ������ vector ���ô�С�������� vector.reserve(33)����Ϊ log(2147483648, 2) = 33
        // ���ӣ�80 / 3
        // scr_div = -3, -6, -12, -24, -48, -96 |  -96 > 81������ֹͣ����
        // scr_res =  1,  2 ,  4,   8,  16,  32 |
        vector<int> scr_div{ divisor }, scr_res{ 1 };
        while (scr_div.back() > dividend&& scr_div.back() > -1073741825) {
            scr_div.push_back(scr_div.back() + scr_div.back());
            scr_res.push_back(scr_res.back() + scr_res.back());
        }
        // 4. �������ĩβ�����Խ����Ӽ�ȥ `scr_div` �о���ֵ������
        //    (-80) - (-48) => (-32) - (-24) => (-8) - (-6) => (-2) |
        //              16   +            8   +          2          = 26
        int result = 0;
        for (size_t i = scr_div.size(); i-- > 0; ) {
            if (dividend <= scr_div[i]) {
                dividend -= scr_div[i];
                result += scr_res[i];
            }
        }
        // 5. �����ų˻������õ����ս����
        return sgn ? result : -result;
    }
};

TEST(e0100, e0029) {
    ASSERT_EQ(Solution().divide(10, 3), 3);
    ASSERT_EQ(Solution().divide(7, -3), -2);
}

/* �ʼǣ�https://leetcode-cn.com/problems/divide-two-integers/solution/divisor-jin-zhi-jie-lei-si-yu-shi-xian-log2bu-shi-/

����ⱻ��ΪԽ��ͳ�ʱ�˻��˺ö�� hhh

ͨ���ķ����ƺ���ʹ����λ������Ҳ�в����õݹ�ġ�˵ʵ���һ���������ġ�������Ϊ�ǿư�ѧ�������������Ҹо���̫ϰ�ߡ��Ҿͳ������Ҹ�ϲ�õķ�ʽ���˷ѵ��ڴ棬��ʵ�������� log2 �Ĺ��ܣ�����������⡣

�������ʹ����ȡ��ֵ���������������Ҫ�ܶ� if �ж���䡣

## ����˼·

�������� `[-80, -3]` ���ԣ��������ǿ�һ������ `scr_div` (scratch divisor)��ʹ������ĵ�һ����Ϊ��ĸ `divisor = 3`���Һ�һ����ǡ�ñ�ǰһ������һ�������Ӧһ�� `scr_res` (scratch result) ���飬�� 2 �����ȱ����У�

```c++
scr_div = { -3,  -6, -12, -24, -48, -96 }
scr_res = {  1,   2 ,  4,   8,  16,  32 }
```

������ǳ���

- �� -80 ��ȥ `scr_div` ����ĩλ�� -96�����⽫�����㣻
- �� -80 ��ȥ -48���õ� -32���� `scr_div` �е� -48 ��Ӧ `scr_res` �е� 16����˽�� `result += 16`��
- ͬ��-32 ��ȥ -24 �õ� -8���� `scr_div` �е� -24 ��Ӧ `scr_res` �е� 8����˽�� `result += 8`��
- �� -8 ��ȥ -12 ������㣬������� -12 �������
- �Դ����ƣ��õ� `result = 16 = 8 + 2 = 26`��

����Ĺ��̿��Լ򵥱�ʾΪ
```
(-80) - (-48) => (-32) - (-24) => (-8) - (-6) => (-2) |
          16   +            8   +          2          = 26
```

�������ʵ��֪�������Ľ���� $n =$ `result`����ô�ù��̵�ʱ����ڴ渴�ӶȻ��� $O(\log n)$���� $n$ �����ܴ��� $2^{32}$�����һ����˵���Ǻܿ�ġ����������ʱ������� 4ms ���ҡ�

����ݹ��������£�����Ҳ��Ҫ�õ���ô����ڴ�ռ䣻��Ϊ�����Ķ�ջҲ��ռ�ڴ�ռ�ġ�

## ���壺int ���

Ϊ�˱��� int ������⣬�����������۷�ĸ `divisor` Ϊ 1 �� -1 �������һ�������������µĽ��� trival �ģ���һ������Ҫ���ⶨ��

```c++
-2147483648 / -1 = 2147483647
```

�����Ĵ���˼·�Ĺ��̣�����Ҫ���˷�ĸ `divisor` �ͷ��� `dividend` ȡ�̶��ķ��š����ǳ�������Ҫ����������ض������ǵķ��š�
�����ǲ�������Ϊ���ţ���Ϊ������ֵ��������Դ�һЩ��

## ����ʵ��

```c++
class Solution {
public:
    int divide(int dividend, int divisor) {
        // 0. �ų��󲿷ּ������
        //    ����Ҫע�⣬����û���ų�������� dividend = -2147483648 �� divisor != (+/-) 1
        if (divisor == 1) return dividend;
        else if (divisor == -1) return (dividend == -2147483648) ? 2147483647 : -dividend;
        // 1. ��ȡ������ֵ�ķ���
        bool sgn = (dividend > 0 == divisor > 0);
        // 2. ���������ĸ��ȡΪ��ֵ (������� dividend = 2147483648)
        if (dividend > 0) dividend = -dividend;
        if (divisor > 0) divisor = -divisor;
        // 3. ���������飬��һ���� ��ĸ * 2^n��������� 2^n
        //    ���ϣ������ vector ���ô�С�������� vector.reserve(33)����Ϊ log(2147483648, 2) = 33
        // ���ӣ�80 / 3
        // scr_div = -3, -6, -12, -24, -48, -96 |  -96 > 81������ֹͣ����
        // scr_res =  1,  2 ,  4,   8,  16,  32 |
        vector<int> scr_div{ divisor }, scr_res{ 1 };
        while (scr_div.back() > dividend && scr_div.back() > -1073741825) {
            scr_div.push_back(scr_div.back() + scr_div.back());
            scr_res.push_back(scr_res.back() + scr_res.back());
        }
        // 4. �������ĩβ�����Խ����Ӽ�ȥ `scr_div` �о���ֵ������
        //    (-80) - (-48) => (-32) - (-24) => (-8) - (-6) => (-2) |
        //              16   +            8   +          2          = 26
        int result = 0;
        for (size_t i = scr_div.size(); i-- > 0; ) {
            if (dividend <= scr_div[i]) {
                dividend -= scr_div[i];
                result += scr_res[i];
            }
        }
        // 5. �����ų˻������õ����ս����
        return sgn ? result : -result;
    }
};
```

*/