// N-th Fibonacci (0-indexed)

#include <iostream>
using namespace std;

int main() {
    long long n; if (!(cin >> n)) return 0;
    unsigned long long a = 0, b = 1;
    if (n == 0) { cout << 0; return 0; }
    for (long long i = 2; i <= n; ++i) { unsigned long long nxt = a + b; a = b; b = nxt; }
    cout << b;
    return 0;
}


