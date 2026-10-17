// Intersections of Interval Lists

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> first(n), second(m);
    for (auto &[start, end] : first) cin >> start >> end;
    for (auto &[start, end] : second) cin >> start >> end;

    int i = 0, j = 0;
    while (i < n && j < m) {
        int start = max(first[i].first, second[j].first);
        int end = min(first[i].second, second[j].second);
        if (start <= end) cout << start << ' ' << end << '\n';
        if (first[i].second < second[j].second) i++;
        else j++;
    }
    return 0;
}
