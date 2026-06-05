// Prime check

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n; if (!(cin >> n)) return 0;
    if (n < 2) { cout << "No"; return 0; }
    for (long long i = 2; i * i <= n; ++i) if (n % i == 0) { cout << "No"; return 0; }
    cout << "Yes";
    return 0;
}
