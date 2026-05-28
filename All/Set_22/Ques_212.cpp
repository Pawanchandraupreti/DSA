// Sieve of Eratosthenes - Print primes up to N

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    if(!(cin >> n)) return 0;
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int q = p*p; q <= n; q += p) isPrime[q] = false;
        }
    }
    for (int i = 2; i <= n; ++i) if (isPrime[i]) cout << i << " ";
    return 0;
}
