// Kth Largest Element (Min Heap)

#include <iostream>
#include <queue>
using namespace std;

int main() {

    int arr[] = {3,2,1,5,6,4};
    int n = 6, k = 2;

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0;i<n;i++) {
        pq.push(arr[i]);

        if(pq.size() > k)
            pq.pop();
    }

    cout << pq.top();
}