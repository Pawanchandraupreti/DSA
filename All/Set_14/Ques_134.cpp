// Sparse Table (Range Minimum Query)
// Time Complexity: Preprocessing O(n log n), query O(1)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {7, 2, 3, 0, 5, 10, 3, 12, 18};
    int n = arr.size();

    int LOG = 0;
    while((1 << LOG) <= n) LOG++;

    vector<vector<int>> st(LOG, vector<int>(n));
    for(int i = 0; i < n; i++) st[0][i] = arr[i];

    for(int j = 1; j < LOG; j++) {
        for(int i = 0; i + (1 << j) <= n; i++) {
            st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }


    
    auto rangeMin = [&](int l, int r) {
        int len = r - l + 1;
        int j = 0;
        while((1 << (j + 1)) <= len) j++;
        return min(st[j][l], st[j][r - (1 << j) + 1]);
    };

    cout << rangeMin(0, 4) << "\n";
    cout << rangeMin(4, 7);
}
