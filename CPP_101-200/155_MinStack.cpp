#include "errors.h"
#include <list>

using namespace std;

// 155. Min Stack - Easy - Stack/Design
// -------------------------------------------------------------
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
// - push(x) -- Push element x onto stack.
// - pop() -- Removes the element on top of the stack.
// - top() -- Get the top element.
// - getMin() -- Retrieve the minimum element in the stack.
// -------------------------------------------------------------
// Solve #1 | 07/06/20 | Time: 10:03 | Avg. Runtime: 66.4ms

class MinStack {
public:
    // Default constructor
    MinStack() {}

    void push(int x) { // O(1) time, O(1) space
        m_stack.push_front(x);
        // Update minimum element if necessary
        if (x < m_min)
            m_min = x;
    }

    void pop() { // O(N) time, O(1) space
        // If the top element is the minimum element
        if (*m_stack.begin() == m_min) {
            // Initialize
            m_min = INT_MAX;
            auto iter = m_stack.begin() + 1;
            // Iterate through stack
            for (; iter != m_stack.end(); iter++)
            {
                // Get minimum element
                if (*iter < m_min)
                    m_min = *iter;
            }
        }
        // Delete old top element
        m_stack.erase(m_stack.begin());
    }

    int top() { // O(1) time, O(1) space
        return *(m_stack.begin());
    }

    int getMin() { // O(1) time, O(1) space
        return m_min;
    }

private:
    list<int> m_stack; // List to model the stack
    int m_min = INT_MAX; // Track minimum element
};
