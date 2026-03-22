// Painter Partition Problem

#include <iostream>
using namespace std;

bool possible(int arr[], int n, int k, int maxTime) {
    int painters = 1, curr = 0;

    for(int i=0;i<n;i++) {
        if(arr[i] > maxTime) return false;

        if(curr + arr[i] > maxTime) {
            painters++;
            curr = arr[i];
        }
        else
            curr += arr[i];
    }
    return painters <= k;
}

int main() {
    int arr[] = {10,20,30,40};
    int n = 4, k = 2;

    int low = 0, high = 100, ans;

    while(low <= high) {
        int mid = (low + high)/2;

        if(possible(arr,n,k,mid)) {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    cout << ans;
}