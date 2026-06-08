// K-th smallest element in union of two sorted arrays

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

long long kthInTwo(const vector<long long>& A, const vector<long long>& B, long long k) {
    int n = A.size(), m = B.size();
    int lo = max(0LL, k - m), hi = min<long long>(k, n);
    while (lo < hi) {
        int i = (lo + hi) / 2;
        int j = k - i;
        long long Aleft = (i <= 0) ? LLONG_MIN : A[i-1];
        long long Aright = (i >= n) ? LLONG_MAX : A[i];
        long long Bleft = (j <= 0) ? LLONG_MIN : B[j-1];
        long long Bright = (j >= m) ? LLONG_MAX : B[j];
        if (Aleft > Bright) hi = i;
        else if (Bleft > Aright) lo = i + 1;
        else {
            return max(Aleft, Bleft);
        }
    }
    int i = lo; int j = k - i;
    long long Aleft = (i <= 0) ? LLONG_MIN : A[i-1];
    long long Bleft = (j <= 0) ? LLONG_MIN : B[j-1];
    return max(Aleft, Bleft);
}

int main() {
    int n, m; if (!(cin >> n >> m)) return 0;
    vector<long long> A(n), B(m);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int j = 0; j < m; ++j) cin >> B[j];
    long long k; if (!(cin >> k)) return 0;
    if (k < 1 || k > (long long)n + m) { cout << "-1"; return 0; }
    cout << kthInTwo(A, B, k);
    return 0;
}



