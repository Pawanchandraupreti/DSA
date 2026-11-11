// Maximum Bipartite Matching

#include <bits/stdc++.h>
using namespace std;

int main() {
    int leftSize, rightSize, edges;
    cin >> leftSize >> rightSize >> edges;
    vector<vector<int>> graph(leftSize);
    while (edges--) {
        int left, right;
        cin >> left >> right;
        graph[left].push_back(right);
    }
    vector<int> pairLeft(leftSize, -1), pairRight(rightSize, -1), distance(leftSize);
    auto bfs = [&]() {
        queue<int> pending;
        for (int left = 0; left < leftSize; left++) {
            if (pairLeft[left] == -1) distance[left] = 0, pending.push(left);
            else distance[left] = -1;
        }
        bool reachable = false;
        while (!pending.empty()) {
            int left = pending.front(); pending.pop();
            for (int right : graph[left]) {
                int next = pairRight[right];
                if (next == -1) reachable = true;
                else if (distance[next] == -1) distance[next] = distance[left] + 1, pending.push(next);
            }
        }
        return reachable;
    };
    function<bool(int)> dfs = [&](int left) {
        for (int right : graph[left]) {
            int next = pairRight[right];
            if (next == -1 || (distance[next] == distance[left] + 1 && dfs(next))) {
                pairLeft[left] = right;
                pairRight[right] = left;
                return true;
            }
        }
        distance[left] = -1;
        return false;
    };
    int answer = 0;
    while (bfs()) for (int left = 0; left < leftSize; left++)
        if (pairLeft[left] == -1 && dfs(left)) answer++;
    cout << answer << '\n';
    return 0;
}
