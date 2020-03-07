// https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/

// 未完成题目
// 开始题意理解错误

#include "extern.h"

class LCOF5902 {
    deque<int> _deq{};
    queue<int> _que{};
public:
    LCOF5902() {}

    int max_value() {
        return _deq.empty() ? -1 : _deq.back();
    }

    void push_back(int value) {
        while (!_deq.empty() && _deq.back() >= value) _deq.pop_back();
        _que.push(value);
        _deq.push_back(value);
    }

    int pop_front() {
        if (_que.empty()) return -1;
        int result = _que.front();
        _que.pop();
        if (_deq.front() == result) _deq.pop_front();
        return result;
    }
};

TEST(lcof, lcof5902) {
    LCOF5902 que;
    que.push_back(1);
    que.push_back(2);
    ASSERT_EQ(que.max_value(), 2);
    ASSERT_EQ(que.pop_front(), 1);
    ASSERT_EQ(que.max_value(), 2);
}
