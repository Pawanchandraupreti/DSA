// Place cows in stalls such that minimum distance is maximized

#include <iostream>
#include <algorithm>
using namespace std;

bool canPlace(int stalls[], int n, int cows, int dist) {
    int count = 1, last = stalls[0];

    for(int i=1;i<n;i++) {
        if(stalls[i] - last >= dist) {
            count++;
            last = stalls[i];
        }
    }
    return count >= cows;
}

int main() {
    int stalls[] = {1,2,4,8,9};
    int n = 5, cows = 3;

    sort(stalls, stalls + n);

    int low = 1, high = stalls[n-1] - stalls[0];
    int ans = 0;

    while(low <= high) {
        int mid = (low + high)/2;

        if(canPlace(stalls,n,cows,mid)) {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    cout << ans;
}