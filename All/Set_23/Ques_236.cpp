// Maximum element in array

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; if (!(cin >> n)) return 0;
    long long mx = LLONG_MIN;
    for (int i = 0; i < n; ++i) { long long x; cin >> x; mx = max(mx, x); }
    cout << mx;
    return 0;
}


