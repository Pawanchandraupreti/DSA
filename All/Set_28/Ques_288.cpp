// N-th term of a linear recurrence using matrix exponentiation

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
static const ll MOD = 1000000007LL;

struct Matrix {
    int n;
    vector<vector<ll>> a;
    Matrix(int n = 0, bool ident = false) : n(n), a(n, vector<ll>(n, 0)) {
        if (ident) for (int i = 0; i < n; ++i) a[i][i] = 1;
    }
};

Matrix mul(const Matrix& x, const Matrix& y) {
    Matrix r(x.n);
    for (int i = 0; i < x.n; ++i) {
        for (int k = 0; k < x.n; ++k) if (x.a[i][k]) {
            for (int j = 0; j < x.n; ++j) {
                r.a[i][j] = (r.a[i][j] + x.a[i][k] * y.a[k][j]) % MOD;
            }
        }
    }
    return r;
}

Matrix mpow(Matrix base, long long exp) {
    Matrix res(base.n, true);
    while (exp > 0) {
        if (exp & 1) res = mul(res, base);
        base = mul(base, base);
        exp >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    long long n;
    if (!(cin >> k >> n)) return 0;
    vector<ll> init(k), coef(k);
    for (int i = 0; i < k; ++i) cin >> init[i];
    for (int i = 0; i < k; ++i) cin >> coef[i];

    if (n <= k) {
        cout << (init[n - 1] % MOD + MOD) % MOD;
        return 0;
    }

    Matrix trans(k);
    for (int i = 0; i < k; ++i) trans.a[0][i] = (coef[i] % MOD + MOD) % MOD;
    for (int i = 1; i < k; ++i) trans.a[i][i - 1] = 1;

    Matrix p = mpow(trans, n - k);
    ll ans = 0;
    for (int i = 0; i < k; ++i) {
        ans = (ans + p.a[0][i] * ((init[k - 1 - i] % MOD + MOD) % MOD)) % MOD;
    }
    cout << ans;
    return 0;
}

