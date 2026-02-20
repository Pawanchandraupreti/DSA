// 3Sum (Basic Version)

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {-1,0,1,2,-1,-4};
    int n = 6;

    sort(arr, arr + n);

    for (int i = 0; i < n - 2; i++) {
        int l = i + 1, r = n - 1;

        while (l < r) {
            int sum = arr[i] + arr[l] + arr[r];

            if (sum == 0) {
                cout << arr[i] << " " << arr[l] << " " << arr[r] << endl;
                l++; r--;
            }
            else if (sum < 0)
                l++;
            else
                r--;
        }
    }

    return 0;
}


