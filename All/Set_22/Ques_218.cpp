// Index of Maximum Element

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; if(!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    if (n == 0) { cout << -1; return 0; }
    int idx = 0;
    for (int i = 1; i < n; ++i) if (a[i] > a[idx]) idx = i;
    cout << idx;
    return 0;
}



