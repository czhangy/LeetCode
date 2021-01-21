#include "errors.h"
#include <queue>

using namespace std;

// 225. Implement Stack Using Queues - Easy - Stack/Design
// -------------------------------------------------------------
// Implement a last in first out (LIFO) stack using only two queues.
// The implemented stack should support all the functions of a normal queue (push, top, pop, and empty).
// Implement the MyStack class:
// - void push(int x) Pushes element x to the top of the stack.
// - int pop() Removes the element on the top of the stack and returns it.
// - int top() Returns the element on the top of the stack.
// - bool empty() Returns true if the stack is empty, false otherwise.
// -------------------------------------------------------------
// Solve #1 | 07/13/20 | Time: 8:08 | Avg. Runtime: 4ms

class MyStack {
public:
    // Default constructor
    MyStack() {}

    void push(int x) { // O(N) time, O(N) space
        // Initialize
        queue<int> temp;
        // Place x at front of queue --> "top" of stack
        temp.push(x);
        // Push all existing elements into new queue
        while (!m_queue.empty()) {
            int val = m_queue.front();
            temp.push(val);
            m_queue.pop();
        }
        // Set this MyStack's queue to the newly constructed queue
        m_queue = temp;
    }

    int pop() { // O(1) time, O(1) space
        // Get element
        int temp = m_queue.front();
        m_queue.pop();
        return temp;
    }

    int top() { // O(1) time, O(1) space
        // Front of queue --> "top" of stack
        return m_queue.front();
    }

    bool empty() { // O(1) time, O(1) space
        return m_queue.empty();
    }

private:
    queue<int> m_queue; // Queue to model the stack
};
