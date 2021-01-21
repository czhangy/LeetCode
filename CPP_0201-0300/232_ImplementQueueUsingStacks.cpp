#include "errors.h"
#include <stack>

using namespace std;

// 232. Implement Queue Using Stacks - Easy - Stack/Design
// -------------------------------------------------------------
// Implement a first in first out (FIFO) queue using only two stacks.
// The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
// Implement the MyQueue class:
// - void push(int x) Pushes element x to the back of the queue.
// - int pop() Removes the element from the front of the queue and returns it.
// - int peek() Returns the element at the front of the queue.
// - bool empty() Returns true if the queue is empty, false otherwise.
// -------------------------------------------------------------
// Solve #1 | 07/14/20 | Time: 4:15 | Avg. Runtime: 1.6ms

class MyQueue {
public:
    // Default constructor
    MyQueue() {}
    

    void push(int x) { // O(N) time, O(N) space
        // Initialize
        stack<int> revStack;
        // Build reversed stack
        while (!m_stack.empty()) {
            revStack.push(m_stack.top());
            m_stack.pop();
        }
        // Place new element at bottom of stack --> back of queue
        m_stack.push(x);
        // Refill stack with old elements
        while (!revStack.empty()) {
            m_stack.push(revStack.top());
            revStack.pop();
        }
    }

    int pop() { // O(1) time, O(1) space
        // Get top/front value
        int temp = m_stack.top();
        m_stack.pop();
        return temp;
    }

    int peek() { // O(1) time, O(1) space
        // Top of stack --> front of queue
        return m_stack.top();
    }

    bool empty() { // O(1) time, O(1) space
        return m_stack.empty();
    }

private:
    stack<int> m_stack; // Stack to model the queue
};
