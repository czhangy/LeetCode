#include "errors.h"
#include <queue>

using namespace std;

// 933. Number Of Recent Calls - Easy - Queue
// -------------------------------------------------------------
// You have a RecentCounter class which counts the number of recent requests within a certain time frame.
// Implement the RecentCounter class:
// - RecentCounter() Initializes the counter with zero recent requests.
// - int ping(int t) Adds a new request at time t, where t represents some time in milliseconds, and returns the number of requests that has happened in the past 3000 milliseconds (including the new request). Specifically, return the number of requests that have happened in the inclusive range [t - 3000, t].
// It is guaranteed that every call to ping uses a strictly larger value of t than the previous call.
// -------------------------------------------------------------
// Solve #1 | 09/28/20 | Time: 6:46 | Avg. Runtime: 206.4ms

class RecentCounter {
public:
    // Default constructor
    RecentCounter() {}

    int ping(int t) { // O(N) time, O(1) space
        // Pop any requests older than t - 3000 off
        while (!m_queue.empty() && m_queue.front() < t - 3000)
            m_queue.pop();
        // Account for new request
        m_queue.push(t);
        return m_queue.size();
    }

private:
    queue<int> m_queue; // Use a queue for request handling
};
