// Check Sorted (non-decreasing)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; if(!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    bool sorted = true;
    for (int i = 1; i < n; ++i) if (a[i] < a[i-1]) { sorted = false; break; }
    cout << (sorted ? 1 : 0);
    return 0;
}


