// Minimum Genetic Mutation

#include <bits/stdc++.h>
using namespace std;

int main() {
    string start, target;
    int n;
    cin >> start >> target >> n;
    unordered_set<string> bank;
    for (int i = 0; i < n; i++) {
        string gene;
        cin >> gene;
        bank.insert(gene);
    }
    queue<pair<string, int>> q;
    q.push({start, 0});
    string letters = "ACGT";
    while (!q.empty()) {
        auto [gene, steps] = q.front();
        q.pop();
        if (gene == target) {
            cout << steps << '\n';
            return 0;
        }
        for (int i = 0; i < (int)gene.size(); i++) {
            string next = gene;
            for (char letter : letters) {
                next[i] = letter;
                if (bank.count(next)) {
                    bank.erase(next);
                    q.push({next, steps + 1});
                }
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}
