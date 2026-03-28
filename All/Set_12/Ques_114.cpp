// Merge K Sorted Arrays (Heap)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    vector<vector<int>> arr = {
        {1,4,7},
        {2,5,8},
        {3,6,9}
    };

    priority_queue<pair<int,pair<int,int>>,
                   vector<pair<int,pair<int,int>>>,
                   greater<>> pq;

    for(int i=0;i<arr.size();i++) {
        pq.push({arr[i][0], {i,0}});
    }

    vector<int> result;

    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int val = top.first;
        int row = top.second.first;
        int col = top.second.second;

        result.push_back(val);

        if(col + 1 < arr[row].size()) {
            pq.push({arr[row][col+1], {row,col+1}});
        }
    }

    for(int x : result)
        cout << x << " ";
}
