// Split Array Largest Sum

#include <iostream>
using namespace std;

bool check(int arr[], int n, int k, int maxSum) {
    int parts = 1, sum = 0;

    for(int i=0;i<n;i++) {
        if(sum + arr[i] > maxSum) {
            parts++;
            sum = arr[i];
        }
        else
            sum += arr[i];
    }
    return parts <= k;
}

int main() {
    int arr[] = {7,2,5,10,8};
    int n = 5, k = 2;

    int low = 0, high = 32, ans;

    while(low <= high) {
        int mid = (low + high)/2;

        if(check(arr,n,k,mid)) {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    cout << ans;
}

