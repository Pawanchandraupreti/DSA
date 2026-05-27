// Rotate Square Matrix 90 Degrees (in-place)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    if(!(cin >> n)) return 0;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    // transpose
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            swap(a[i][j], a[j][i]);
    // reverse each row
    for (int i = 0; i < n; ++i)
        reverse(a[i].begin(), a[i].end());

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cout << a[i][j] << " ";
        cout << '\n';
    }
    return 0;
}


