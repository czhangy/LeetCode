#include "errors.h"
#include <vector>

using namespace std;

// 706. Design HashMap - Easy - Hash Table/Design
// -------------------------------------------------------------
// Design a HashMap without using any built-in hash table libraries.
// To be specific, your design should include these functions:
// - put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
// - get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
// - remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.
// -------------------------------------------------------------
// Solve #1 | 09/05/20 | Time: 22:21 | Avg. Runtime: 256ms

class MyHashMap {
public:
    // Constructor
    MyHashMap() {
        m_size = 0;
        m_numBuckets = 2;
        m_loadFactor = 0.5;
        vector<vector<pair<int, int>>> temp(2);
        m_buckets = temp;
    }

    void put(int key, int value) { // O(1) time, O(1) space
        // Initialize
        auto iter = m_buckets[hash(key)].begin();
        // Position iterator
        for (; iter != m_buckets[hash(key)].end() && iter->first != key; iter++) {}
        // Insert into hash map if key is new
        if (iter == m_buckets[hash(key)].end()) {
            m_buckets[hash(key)].push_back({key, value});
            m_size++;
        // If key exists, map to new value
        } else
            iter->second = value;
        // Rehash if load factor exceeded
        if (m_size > m_numBuckets * m_loadFactor) {
            m_numBuckets <<= 1;
            vector<vector<pair<int, int>>> temp(m_numBuckets);
            // Construct replacement hash map
            for (int i = 0; i < m_buckets.size(); i++)
                for (int j = 0; j < m_buckets[i].size(); j++)
                    temp[hash(m_buckets[i][j].first)].push_back({m_buckets[i][j].first, m_buckets[i][j].second});
            m_buckets = temp;
        }
    }

    int get(int key) { // O(1) time, O(1) space
        // Get bucket
        int index = hash(key);
        // Find key and return value
        for (int i = 0; i < m_buckets[index].size(); i++) {
            if (m_buckets[index][i].first == key)
                return m_buckets[index][i].second;
        }
        // Key not found
        return -1;
    }

    void remove(int key) { // O(1) time, O(1) space
        // Initialize
        int index = hash(key);
        // Find key
        for (int i = 0; i < m_buckets[index].size(); i++) {
            // Remove key-value pair when found
            if (m_buckets[index][i].first == key) {
                m_buckets[index].erase(m_buckets[index].begin() + i);
                m_size--;
                return;
            }
        }
    }

private:
    int m_size, m_numBuckets; // Track hash table size
    double m_loadFactor; // Load factor for optimal rehashing
    vector<vector<pair<int, int>>> m_buckets; // Model hash map as 2D vector

    // Hash function
    int hash(int key) {
        return key % m_numBuckets;
    }
};
