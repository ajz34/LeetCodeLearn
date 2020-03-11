// https://leetcode-cn.com/problems/min-stack/

#include "extern.h"

class MinStack0155 {
    stack<int> stk;
    stack<pair<int, int>> min_stk;
public:
    MinStack0155() {}

    void push(int x) {
        stk.push(x);
        if (min_stk.empty() || x < min_stk.top().first)
            min_stk.push(make_pair(x, stk.size()));
    }

    void pop() {
        stk.pop();
        if (stk.size() < min_stk.top().second) min_stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min_stk.top().first;
    }
};

TEST(e0200, e0155) {
    MinStack0155 minStack = MinStack0155();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    ASSERT_EQ(minStack.getMin(), -3);
    minStack.pop();
    ASSERT_EQ(minStack.top(), 0);
    ASSERT_EQ(minStack.getMin(), -2);

}
