// Binary Search (first occurrence)

#include <iostream>
#include <vector>
using namespace std;

int lowerBound(const vector<int>& a, int x) {
    int l = 0, r = (int)a.size();
    while (l < r) {
        int m = l + (r - l) / 2;
        if (a[m] < x) l = m + 1;
        else r = m;
    }
    return l;
}

int main() {
    int n; if(!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int x; cin >> x;
    int idx = lowerBound(a, x);
    if (idx < n && a[idx] == x) cout << idx;
    else cout << -1;
    return 0;
}

