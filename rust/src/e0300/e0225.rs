use std::collections::VecDeque;

struct MyStack {
    _deque: VecDeque<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyStack {

    /** Initialize your data structure here. */
    fn new() -> Self {
        return MyStack{ _deque: Default::default() };
    }

    /** Push element x onto stack. */
    fn push(&mut self, x: i32) {
        let mut deque = VecDeque::new();
        deque.push_back(x);
        while !self._deque.is_empty() {
            deque.push_back(self._deque.pop_front().unwrap());
        }
        self._deque = deque;
    }

    /** Removes the element on top of the stack and returns that element. */
    fn pop(&mut self) -> i32 {
        return self._deque.pop_front().unwrap();
    }

    /** Get the top element. */
    fn top(&self) -> i32 {
        return *self._deque.front().unwrap() as i32;
    }

    /** Returns whether the stack is empty. */
    fn empty(&self) -> bool {
        return self._deque.is_empty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * let obj = MyStack::new();
 * obj.push(x);
 * let ret_2: i32 = obj.pop();
 * let ret_3: i32 = obj.top();
 * let ret_4: bool = obj.empty();
 */

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_0225() {
        let mut stk = MyStack::new();
        stk.push(1);
        stk.push(2);
        let ret_1 = stk.top();
        let ret_2 = stk.pop();
        let ret_3 = stk.empty();
        // println!("{}, {}, {}", ret_1, ret_2, ret_3);
        assert_eq!(ret_1, 2);
        assert_eq!(ret_2, 2);
        assert_eq!(ret_3, false);
    }
}