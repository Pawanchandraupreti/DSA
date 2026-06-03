// Index of minimum element (first occurrence)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int idx = 0;
    for (int i = 1; i < n; ++i) if (a[i] < a[idx]) idx = i;
    cout << idx;
    return 0;
}
