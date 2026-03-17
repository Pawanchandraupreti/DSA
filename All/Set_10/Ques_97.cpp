// Merge K Sorted Lists (Min Heap)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {

    vector<vector<int>> lists = {
        {1,4,5},
        {1,3,4},
        {2,6}
    };

    priority_queue<pair<int,pair<int,int>>, 
                   vector<pair<int,pair<int,int>>>, 
                   greater<>> pq;

    for(int i=0;i<lists.size();i++) {
        pq.push({lists[i][0], {i,0}});
    }

    vector<int> result;

    while(!pq.empty()) {

        auto top = pq.top();
        pq.pop();

        int val = top.first;
        int row = top.second.first;
        int col = top.second.second;

        result.push_back(val);

        if(col + 1 < lists[row].size()) {
            pq.push({lists[row][col+1], {row,col+1}});
        }
    }

    for(int x : result)
        cout << x << " ";
}