#include "errors.h"
#include <vector>

using namespace std;

// 705. Design HashSet - Easy - Hash Table/Design
// -------------------------------------------------------------
// Design a HashSet without using any built-in hash table libraries.
// To be specific, your design should include these functions:
// - add(value): Insert a value into the HashSet.
// - contains(value) : Return whether the value exists in the HashSet or not.
// - remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.
// -------------------------------------------------------------
// Solve #2 | 09/11/20 | Time: 15:55 | Avg. Runtime: 192ms

class MyHashSet {
public:
    // Constructor
    MyHashSet() : m_loadFactor(0.75), m_numBuckets(2), m_buckets(m_numBuckets), m_size(0) {}

    void add(int key) { // O(1) time, O(1) space
        // Protect against duplicate insertion
        if (contains(key))
            return;
        // Insert into hash table
        int bucket = hash(key);
        m_buckets[bucket].push_back(key);
        m_size++;
        // Rehash using load factor if needed
        if (m_size > m_loadFactor * m_numBuckets) {
            m_numBuckets <<= 1;
            // Fill replacement hash table
            vector<vector<int>> temp(m_numBuckets);
            for (int i = 0; i < m_buckets.size(); i++)
                for (int j = 0; j < m_buckets[i].size(); j++)
                    temp[hash(m_buckets[i][j])].push_back(m_buckets[i][j]);
            // Swap contents
            m_buckets.swap(temp);
        }
    }

    void remove(int key) { // O(1) time, O(1) space
        // If the key doesn't exist, do nothing
        if (!contains(key))
            return;
        // Get bucket
        int bucket = hash(key);
        // Iteratively search for key
        for (int i = 0; i < m_buckets[bucket].size(); i++)
            // Erase the key
            if (m_buckets[bucket][i] == key) {
                m_buckets[bucket].erase(m_buckets[bucket].begin() + i);
                m_size--;
                return;
            }
    }

    bool contains(int key) { // O(1) time, O(1) space
        // Get bucket
        int bucket = hash(key);\
        // Iterate through buckets to find key
        for (int i = 0; i < m_buckets[bucket].size(); i++)
            if (m_buckets[bucket][i] == key)
                return true;
        return false;
    }

private:
    double m_loadFactor; // Load factor to optimize rehashing
    int m_numBuckets; // Number of buckets
    int m_size; // Total elements
    vector<vector<int>> m_buckets; // Use vector to model hash table

    // Hash function
    int hash(int key) {
        return key % m_numBuckets;
    }
};
