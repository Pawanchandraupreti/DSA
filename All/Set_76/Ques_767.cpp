// Range Sum Query

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, queries;
    cin >> n;
    vector<long long> prefix(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        prefix[i] = prefix[i - 1] + x;
    }
    cin >> queries;
    while (queries--) {
        int left, right;
        cin >> left >> right;
        cout << prefix[right + 1] - prefix[left] << '\n';
    }
    return 0;
}

