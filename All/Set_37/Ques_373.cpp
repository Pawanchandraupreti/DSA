// Find the nth Fibonacci number

#include <bits/stdc++.h>
using namespace std;

long long fibonacci(int n) {
    if (n <= 1) return n;

    long long prev = 0;
    long long curr = 1;

    for (int i = 2; i <= n; ++i) {
        long long next = prev + curr;
        prev = curr;
        curr = next;
    }

    return curr;
}

int main() {
    int n;
    cin >> n;

    cout << fibonacci(n);
    return 0;
}


