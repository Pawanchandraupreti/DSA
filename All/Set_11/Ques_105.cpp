// Minimum Days to Make Bouquets

#include <iostream>
using namespace std;

bool canMake(int bloom[], int n, int m, int k, int day) {
    int flowers = 0, bouquets = 0;

    for(int i=0;i<n;i++) {
        if(bloom[i] <= day) {
            flowers++;
            if(flowers == k) {
                bouquets++;
                flowers = 0;
            }
        }
        else
            flowers = 0;
    }

    return bouquets >= m;
}

int main() {
    int bloom[] = {1,10,3,10,2};
    int n = 5, m = 3, k = 1;

    int low = 1, high = 10, ans = -1;

    while(low <= high) {
        int mid = (low + high)/2;

        if(canMake(bloom,n,m,k,mid)) {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    cout << ans;


}