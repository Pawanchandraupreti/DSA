// N-th Fibonacci using matrix exponentiation

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const ll MOD = 1000000007LL;

struct Mat {
    ll a[2][2];

    Mat() {
        a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;
    }
};

Mat mul(const Mat& x, const Mat& y) {
    Mat r;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                r.a[i][j] = (r.a[i][j] + x.a[i][k] * y.a[k][j]) % MOD;
            }
        }
    }
    return r;
}

Mat mpow(Mat base, long long e) {
    Mat res;
    res.a[0][0] = res.a[1][1] = 1;

    while (e) {
        if (e & 1) res = mul(res, base);
        base = mul(base, base);
        e >>= 1;
    }

    return res;
}

int main() {
    long long n;
    if (!(cin >> n)) return 0;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    Mat M;
    M.a[0][0] = 1;
    M.a[0][1] = 1;
    M.a[1][0] = 1;
    M.a[1][1] = 0;

    Mat R = mpow(M, n - 1);
    cout << (R.a[0][0]) % MOD;
    return 0;
}

