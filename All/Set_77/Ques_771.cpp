// Minimum Genetic Mutation

#include <bits/stdc++.h>
using namespace std;

int main() {
    string start, finish;
    int n;
    cin >> start >> finish >> n;
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
        if (gene == finish) {
            cout << steps << '\n';
            return 0;
        }
        for (int i = 0; i < (int)gene.size(); i++) {
            char saved = gene[i];
            for (char ch : letters) {
                gene[i] = ch;
                if (bank.count(gene)) {
                    bank.erase(gene);
                    q.push({gene, steps + 1});
                }
            }
            gene[i] = saved;
        }
    }
    cout << -1 << '\n';
    return 0;
}
