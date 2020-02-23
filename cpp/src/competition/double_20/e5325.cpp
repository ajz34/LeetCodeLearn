// https://leetcode-cn.com/problems/number-of-substrings-containing-all-three-characters/

#include "extern.h"

class Solution {
public:
    int numberOfSubstrings(string s) {
        if (s.size() <= 2) return 0;
        // ������ `with_abc`����¼��ǰ�������ַ��ĳ��ִ���
        unordered_map<char, int> with_abc{ {'a', 0}, {'b', 0}, {'c', 0} };
        // ���� `check_abc`������������Ƿ�����������ַ�
        auto check_abc = [&with_abc]() { return (with_abc['a'] > 0) && (with_abc['b'] > 0) && (with_abc['c'] > 0); };
        // ��ָ�� pl����ָ�� pr��ָ���� int �����
        int pl = 0; int pr = pl;
        // result
        int result = 0;
        // �������ַ��� `s` �ĵ�һ���ַ���ʼ������
        with_abc[s[pl]] += 1;

        while (pr < s.size()) {
            if (!check_abc()) {               // ����ǰ���������������ַ�
                ++pr; with_abc[s[pr]] += 1;   // ��ô��ָ�� +1 ����������
                if (pr >= s.size()) break;    // ����ָ�볬���ַ���������ѭ��
            }
            else { with_abc[s[pl]] -= 1; ++pl; }       // ����ǰ�������������ַ�����ô��ָ�� +1 ����������
            if (check_abc()) result += s.size() - pr;  // ��ָ���ƶ�����������������ַ�����ô���½��
        }
        return result;
    }
};

TEST(double20, e5325) {
    ASSERT_EQ(Solution().numberOfSubstrings("abcabc"), 10);
    ASSERT_EQ(Solution().numberOfSubstrings("aaacb"), 3);
    ASSERT_EQ(Solution().numberOfSubstrings("abc"), 1);
}

/* ��⣺https://leetcode-cn.com/problems/number-of-substrings-containing-all-three-characters/solution/shuang-zhi-zhen-yu-suo-yin-biao-yi-aabcbabc-zi-fu-/

�� 3 ���������˫ָ����������ʵ�֡�

## ���¹���

���Ǽ������Ը���һЩ���ַ��� `aabcbabc` �Ľ�������� 18��

���ȣ����ǹ���һ������ abc ������������ `with_abc`�����ǳ�ʼ����ָ�� `pl = 0`���Լ���ָ�� `pr = 0`����ѭ����ѭ����

- ��ǰ�������
  ```
  aabcbabc
  -
  ```
  ��ǰ������ֻ��һ�� `a`���������� `a`, `b`, `c` ���ٸ�һ�������������ָ�룬ֱ�������� `a`, `b`, `c` ���ٸ�һ����

- ���ڵ������ `pl = 0`, `pr = 3`
  ```
  aabcbabc
  ----
  ```
  ��������£����Ƿ�������Ϊ�𰸵İ��� `abc` ���ַ������� `aabc`, `aabcb`, `aabcba`, `aabcbab`, `aabcbabc` ���֡�������ǡ�ö�Ӧ `s.size() - pr = 8 - 3 = 5`��
  �������������ָ�롣

- ���ڵ������ `pl = 1`, `pr = 3`��������Ȼ���������� `a`, `b`, `c` ���ٸ�һ����
  ```
  aabcbabc
   ---
  ```
  ͬ���أ����������ֿ��ܵĽ������Ӧ `s.size() - pr = 8 - 3 = 5`��
  ������������ָ�롣

- ���ڵ������ `pl = 2`, `pr = 3`������������ `a`��
  ```
  aabcbabc
    --
  ```
  ������Ҫ������ָ�룬ʹ���������� `a` (`pl = 2`, `pr = 5`)��
  ```
  aabcbabc
    ----
  ```
  ��ʱ���ܵĴ��� 3 �֡�

������������ǾͿ��Եõ�����ˡ�ʣ�µ������

- ```
  aabcbabc  // 3 ��
     ---
  ```
- ```
  aabcbabc  // 1 ��
      ----
  ```
- ```
  aabcbabc  // 1 ��
       ---
  ```

�ܹ� 5 + 5 + 3 + 3 + 1 + 1 = 18 �������

## ���Ӷ�

���������룬���Կ�����ÿ�� `while` ��䶼����һ��ָ�룬������ָ�������ָ�룬���� `while` ������ǳ������Ӷȣ�������帴�Ӷ��� $O(n)$��

����ʱ�е㳤������� 170 ms ���� =.=

## ����

```c++
class Solution {
public:
    int numberOfSubstrings(string s) {
        if (s.size() <= 2) return 0;
        // ������ `with_abc`����¼��ǰ�������ַ��ĳ��ִ���
        unordered_map<char, int> with_abc{ {'a', 0}, {'b', 0}, {'c', 0} };
        // ���� `check_abc`������������Ƿ�����������ַ�
        auto check_abc = [&with_abc]() { return (with_abc['a'] > 0) && (with_abc['b'] > 0) && (with_abc['c'] > 0); };
        // ��ָ�� pl����ָ�� pr��ָ���� int �����
        int pl = 0; int pr = pl;
        // result
        int result = 0;
        // �������ַ��� `s` �ĵ�һ���ַ���ʼ������
        with_abc[s[pl]] += 1;

        while (pr < s.size()) {
            if (!check_abc()) {               // ����ǰ���������������ַ�
                ++pr; with_abc[s[pr]] += 1;   // ��ô��ָ�� +1 ����������
                if (pr >= s.size()) break;    // ����ָ�볬���ַ���������ѭ��
            }
            else { with_abc[s[pl]] -= 1; ++pl; }       // ����ǰ�������������ַ�����ô��ָ�� +1 ����������
            if (check_abc()) result += s.size() - pr;  // ��ָ���ƶ�����������������ַ�����ô���½��
        }
        return result;
    }
};
```

*/
