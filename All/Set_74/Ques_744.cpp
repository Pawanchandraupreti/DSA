// Find the Town Judge

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> score(n + 1);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        score[from]--;
        score[to]++;
    }
    for (int i = 1; i <= n; i++) if (score[i] == n - 1) {
        cout << i << '\n';
        return 0;
    }
    cout << -1 << '\n';
    return 0;
}
