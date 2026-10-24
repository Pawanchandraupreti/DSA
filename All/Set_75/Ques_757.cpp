// Maximum Sum of Three Nonoverlapping Subarrays

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), sums(n - k + 1);
    for (int &x : a) cin >> x;
    long long window = 0;
    for (int i = 0; i < n; i++) {
        window += a[i];
        if (i >= k) window -= a[i - k];
        if (i >= k - 1) sums[i - k + 1] = window;
    }
    int count = sums.size();
    vector<int> bestLeft(count), bestRight(count);
    for (int i = 1; i < count; i++) bestLeft[i] = sums[i] > sums[bestLeft[i - 1]] ? i : bestLeft[i - 1];
    bestRight[count - 1] = count - 1;
    for (int i = count - 2; i >= 0; i--) bestRight[i] = sums[i] >= sums[bestRight[i + 1]] ? i : bestRight[i + 1];
    long long answer = 0;
    for (int middle = k; middle + k < count; middle++) answer = max(answer, (long long)sums[bestLeft[middle - k]] + sums[middle] + sums[bestRight[middle + k]]);
    cout << answer << '\n';
    return 0;
}
