// Maximum Product Subarray

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {2, 3, -2, 4};
    int n = arr.size();
    int maxProd = arr[0];
    int minProd = arr[0];
    int result = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < 0) swap(maxProd, minProd);
        maxProd = max(arr[i], maxProd * arr[i]);
        minProd = min(arr[i], minProd * arr[i]);
        result = max(result, maxProd);
    }

    cout << "Maximum product subarray: " << result << endl;
    return 0;
}
