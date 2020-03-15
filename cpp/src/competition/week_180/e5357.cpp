// https://leetcode-cn.com/problems/design-a-stack-with-increment-operation/

#include "extern.h"

class CustomStack5357 {
    vector<int> vec;
    int maxsize;
public:
    CustomStack5357(int maxSize) {
        vec.reserve(maxSize);
        maxsize = maxSize;
    }

    void push(int x) {
        if (vec.size() < maxsize)
            vec.push_back(x);
    }

    int pop() {
        if (vec.empty()) return -1;
        int result = vec.back();
        vec.pop_back();
        return result;
    }

    void increment(int k, int val) {
        for (int i = 0; i < min(k, maxsize); ++i) {
            vec[i] += val;
        }
    }
};

TEST(week180, e5357) {
    CustomStack5357 customStack = CustomStack5357(3);
    customStack.push(1);
    customStack.push(2);
    ASSERT_EQ(customStack.pop(), 2);
    customStack.push(2);
    customStack.push(3);
    customStack.push(4);
    customStack.increment(5, 100);
    customStack.increment(2, 100);
    ASSERT_EQ(customStack.pop(), 103);
    ASSERT_EQ(customStack.pop(), 202);
    ASSERT_EQ(customStack.pop(), 201);
    ASSERT_EQ(customStack.pop(), -1);
}
