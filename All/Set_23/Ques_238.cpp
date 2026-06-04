// Product of array elements

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; if (!(cin >> n)) return 0;
    long long prod = 1;
    for (int i = 0; i < n; ++i) { long long x; cin >> x; prod *= x; }
    cout << prod;
    return 0;
}


