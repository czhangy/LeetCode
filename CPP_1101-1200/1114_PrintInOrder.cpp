#include "errors.h"
#include <functional>

using namespace std;

// 1114. Print In Order - Easy - Design/Parallelism
// -------------------------------------------------------------
// Suppose we have a class:
// public class Foo {
//  public void first() { print("first"); }
//  public void second() { print("second"); }
//  public void third() { print("third"); }
// }
// The same instance of Foo will be passed to three different threads.
// Thread A will call first(), thread B will call second(), and thread C will call third().
// Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().
// -------------------------------------------------------------
// Solve #1 | 01/21/21 | Time: 3:38 | Avg. Runtime: 2409.6ms

class Foo {
public:
    // Set locks
    Foo() : m_first(false), m_second(false) {}

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        // Unlock next lock
        m_first = true;
    }

    void second(function<void()> printSecond) {
        // Check lock
        if (m_first) {
            // printSecond() outputs "second". Do not change or remove this line.
            printSecond();
            // Unlock next lock
            m_second = true;
        }
        // Retry
        else
            second(printSecond);
    }

    void third(function<void()> printThird) {
        // Check lock
        if (m_second)
            // printThird() outputs "third". Do not change or remove this line.
            printThird();
        // Retry
        else
            third(printThird);
    }

private:
    bool m_first; // Fake locks
    bool m_second;
};
