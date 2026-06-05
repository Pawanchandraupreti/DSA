// Factorial (iterative)

#include <iostream>
using namespace std;

int main() {
    int n; if (!(cin >> n)) return 0;
    unsigned long long res = 1;
    for (int i = 2; i <= n; ++i) res *= i;
    cout << res;
    return 0;
}
