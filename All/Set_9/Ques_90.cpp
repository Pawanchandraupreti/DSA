// LRU Cache (Core Interview Problem)

#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {

    int cap;
    list<pair<int,int>> dq;
    unordered_map<int,list<pair<int,int>>::iterator> mp;

public:

    LRUCache(int capacity) {
        cap=capacity;
    }

    int get(int key) {

        if(mp.find(key)==mp.end())
            return -1;

        auto it=mp[key];
        int value=it->second;

        dq.erase(it);
        dq.push_front({key,value});
        mp[key]=dq.begin();

        return value;
    }

    void put(int key,int value) {

        if(mp.find(key)!=mp.end())
            dq.erase(mp[key]);

        else if(dq.size()==cap) {
            auto last=dq.back();
            mp.erase(last.first);
            dq.pop_back();
        }

        dq.push_front({key,value});
        mp[key]=dq.begin();
    }
};

int main() {

    LRUCache cache(2);

    cache.put(1,1);
    cache.put(2,2);

    cout<<cache.get(1);
}