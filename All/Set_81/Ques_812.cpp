// Minimum Swaps to Sort Array

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    vector<bool> visited(n);
    int answer = 0;
    for (int i = 0; i < n; i++) if (!visited[i] && a[i].second != i) {
        int cycle = 0, current = i;
        while (!visited[current]) {
            visited[current] = true;
            current = a[current].second;
            cycle++;
        }
        answer += cycle - 1;
    }
    cout << answer << '\n';
    return 0;
}
