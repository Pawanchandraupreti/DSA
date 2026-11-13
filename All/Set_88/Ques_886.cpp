// Chinese Remainder Theorem

#include <bits/stdc++.h>
using namespace std;

long long extendedGcd(long long a, long long b, long long &x, long long &y) {
    if (!b) { x = 1; y = 0; return a; }
    long long nextX, nextY;
    long long result = extendedGcd(b, a % b, nextX, nextY);
    x = nextY;
    y = nextX - (a / b) * nextY;
    return result;
}

int main() {
    int count;
    cin >> count;
    long long result = 0, modulus = 1;
    for (int i = 0; i < count; i++) {
        long long remainder, nextModulus;
        cin >> remainder >> nextModulus;
        long long x, y;
        long long common = extendedGcd(modulus, nextModulus, x, y);
        if ((remainder - result) % common) {
            cout << "-1\n";
            return 0;
        }
        long long step = nextModulus / common;
        long long adjustment = ((remainder - result) / common % step + step) % step;
        x = (x % step + step) % step;
        result += modulus * ((__int128)adjustment * x % step);
        modulus = modulus / common * nextModulus;
        result = (result % modulus + modulus) % modulus;
    }
    cout << result << ' ' << modulus << '\n';
    return 0;
}
