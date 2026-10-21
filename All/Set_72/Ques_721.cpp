// Maximum Length Pair Chain

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> pairs(n);
    for (auto &[left, right] : pairs) cin >> left >> right;
    sort(pairs.begin(), pairs.end(), [](auto a, auto b) { return a.second < b.second; });

    int answer = 0, previous = INT_MIN;
    for (auto [left, right] : pairs) {
        if (left > previous) {
            answer++;
            previous = right;
        }
    }
    cout << answer << '\n';
    return 0;
}
