// Floyd Warshall All Pairs Shortest Paths

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    const int inf = 1e9;
    vector<vector<int>> distance(n, vector<int>(n));
    for (auto &row : distance) {
        for (int &value : row) {
            cin >> value;
            if (value == -1) value = inf;
        }
    }

    for (int middle = 0; middle < n; middle++) {
        for (int from = 0; from < n; from++) {
            for (int to = 0; to < n; to++) {
                distance[from][to] = min(distance[from][to], distance[from][middle] + distance[middle][to]);
            }
        }
    }
    for (auto &row : distance) {
        for (int value : row) cout << (value == inf ? -1 : value) << ' ';
        cout << '\n';
    }
    return 0;
}
