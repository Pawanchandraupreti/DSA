// Allocate Minimum Pages

#include <iostream>
using namespace std;

bool isPossible(int arr[], int n, int students, int maxPages) {
    int count = 1, pages = 0;

    for(int i=0;i<n;i++) {
        if(arr[i] > maxPages)
            return false;

        if(pages + arr[i] > maxPages) {
            count++;
            pages = arr[i];
        }
        else
            pages += arr[i];
    }

    return count <= students;
}

int main() {
    int arr[] = {12,34,67,90};
    int n = 4, students = 2;

    int low = 0, high = 203, ans = -1;

    while(low <= high) {
        int mid = (low + high)/2;

        if(isPossible(arr,n,students,mid)) {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    cout << ans;
}

