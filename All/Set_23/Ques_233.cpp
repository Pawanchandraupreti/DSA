// Linear Search (first index of x)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int x; cin >> x;
    for (int i = 0; i < n; ++i) {
        if (a[i] == x) { cout << i; return 0; }
    }
    cout << -1;
    return 0;
}
