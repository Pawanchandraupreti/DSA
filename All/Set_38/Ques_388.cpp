// LRU Cache

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> entries;
    unordered_map<int, list<pair<int, int>>::iterator> locations;

public:
    explicit LRUCache(int cacheCapacity) : capacity(cacheCapacity) {}

    int get(int key) {
        auto location = locations.find(key);
        if (location == locations.end()) {
            return -1;
        }

        int value = location->second->second;
        entries.splice(entries.begin(), entries, location->second);
        return value;
    }

    void put(int key, int value) {
        auto location = locations.find(key);
        if (location != locations.end()) {
            location->second->second = value;
            entries.splice(entries.begin(), entries, location->second);
            return;
        }

        entries.push_front({key, value});
        locations[key] = entries.begin();

        if ((int)entries.size() > capacity) {
            int leastUsedKey = entries.back().first;
            locations.erase(leastUsedKey);
            entries.pop_back();
        }
    }
};

int main() {
    int capacity, operations;
    cin >> capacity >> operations;

    LRUCache cache(capacity);
    for (int operation = 0; operation < operations; ++operation) {
        string command;
        cin >> command;

        if (command == "put") {
            int key, value;
            cin >> key >> value;
            cache.put(key, value);
        } else if (command == "get") {
            int key;
            cin >> key;
            cout << cache.get(key) << ' ';
        }
    }

    return 0;
}
