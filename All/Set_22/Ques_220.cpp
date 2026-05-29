// Reverse Array (print reversed elements)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; if(!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = n-1; i >= 0; --i) {
        cout << a[i];
        if (i) cout << ' ';
    }
    return 0;
}
