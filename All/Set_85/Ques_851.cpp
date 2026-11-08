// Largest Sum After K Negations

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());
    for (int i = 0; i < n && k && a[i] < 0; i++, k--) a[i] = -a[i];
    long long answer = accumulate(a.begin(), a.end(), 0LL);
    if (k % 2) answer -= 2LL * *min_element(a.begin(), a.end());
    cout << answer << '\n';
    return 0;
}
