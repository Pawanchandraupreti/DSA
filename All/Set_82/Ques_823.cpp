// Count Range Sum

#include <bits/stdc++.h>
using namespace std;

long long countRanges(vector<long long> &prefix, int left, int right, long long lower, long long upper) {
    if (right - left <= 1) return 0;
    int middle = (left + right) / 2;
    long long answer = countRanges(prefix, left, middle, lower, upper) + countRanges(prefix, middle, right, lower, upper);
    int low = middle, high = middle;
    for (int i = left; i < middle; i++) {
        while (low < right && prefix[low] - prefix[i] < lower) low++;
        while (high < right && prefix[high] - prefix[i] <= upper) high++;
        answer += high - low;
    }
    inplace_merge(prefix.begin() + left, prefix.begin() + middle, prefix.begin() + right);
    return answer;
}

int main() {
    int n;
    long long lower, upper;
    cin >> n >> lower >> upper;
    vector<long long> prefix(n + 1);
    for (int i = 1; i <= n; i++) { int x; cin >> x; prefix[i] = prefix[i - 1] + x; }
    cout << countRanges(prefix, 0, n + 1, lower, upper) << '\n';
    return 0;
}
