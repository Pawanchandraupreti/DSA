// K Closest Points to Origin

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<long long, pair<int, int>>> a;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back({1LL * x * x + 1LL * y * y, {x, y}});
    }

    sort(a.begin(), a.end());
    for (int i = 0; i < k; i++) {
        cout << a[i].second.first << ' ' << a[i].second.second << '\n';
    }
    return 0;
}

