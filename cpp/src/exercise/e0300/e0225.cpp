// https://leetcode-cn.com/problems/implement-stack-using-queues/

#include "extern.h"

class MyStack {
private:
    queue<int> _que;
public:
    /** Initialize your data structure here. */
    MyStack() {
        _que = {};
    }

    /** Push element x onto stack. */
    void push(int x) {
        queue<int> que{};
        que.push(x);
        while (!_que.empty()) {
            que.push(_que.front());
            _que.pop();
        }
        swap(que, _que);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        assert(!_que.empty());
        int r = _que.front();
        _que.pop();
        return r;
    }

    /** Get the top element. */
    int top() {
        assert(!_que.empty());
        return _que.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return _que.empty();
    }
};

TEST(e0300, e0225) {
    MyStack stk;
    stk.push(1);
    stk.push(2);
    ASSERT_EQ(stk.top(), 2);
    ASSERT_EQ(stk.pop(), 2);
    ASSERT_FALSE(stk.empty());
}
