// Maximum Sum of Two Nonoverlapping Subarrays

#include <bits/stdc++.h>
using namespace std;

long long bestOrder(const vector<int> &a, int first, int second) {
    int n = a.size();
    vector<long long> prefix(n + 1);
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + a[i];
    long long best = 0, answer = 0;
    for (int i = first + second; i <= n; i++) {
        best = max(best, prefix[i - second] - prefix[i - second - first]);
        answer = max(answer, best + prefix[i] - prefix[i - second]);
    }
    return answer;
}

int main() {
    int n, first, second;
    cin >> n >> first >> second;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    cout << max(bestOrder(a, first, second), bestOrder(a, second, first)) << '\n';
    return 0;
}
