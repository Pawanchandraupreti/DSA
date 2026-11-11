// Satisfiability of Boolean Clauses

#include <bits/stdc++.h>
using namespace std;

int main() {
    int variables, clauses;
    cin >> variables >> clauses;
    vector<vector<int>> graph(2 * variables), reverseGraph(2 * variables);
    auto node = [](int literal) {
        int variable = abs(literal) - 1;
        return 2 * variable + (literal < 0);
    };
    for (int i = 0; i < clauses; i++) {
        int first, second;
        cin >> first >> second;
        int a = node(first), b = node(second);
        graph[a ^ 1].push_back(b);
        graph[b ^ 1].push_back(a);
        reverseGraph[b].push_back(a ^ 1);
        reverseGraph[a].push_back(b ^ 1);
    }
    vector<int> order, component(2 * variables), used(2 * variables);
    function<void(int)> visit = [&](int current) {
        used[current] = 1;
        for (int next : graph[current]) if (!used[next]) visit(next);
        order.push_back(current);
    };
    for (int i = 0; i < 2 * variables; i++) if (!used[i]) visit(i);
    function<void(int, int)> assign = [&](int current, int id) {
        component[current] = id;
        used[current] = 1;
        for (int next : reverseGraph[current]) if (!used[next]) assign(next, id);
    };
    fill(used.begin(), used.end(), 0);
    reverse(order.begin(), order.end());
    int id = 0;
    for (int current : order) if (!used[current]) assign(current, id++);
    for (int i = 0; i < variables; i++) {
        if (component[2 * i] == component[2 * i + 1]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
