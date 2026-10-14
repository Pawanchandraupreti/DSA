// Intersection of Two Arrays

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    unordered_set<int> first, answer;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        first.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (first.count(x)) answer.insert(x);
    }

    vector<int> result(answer.begin(), answer.end());
    sort(result.begin(), result.end());
    for (int x : result) cout << x << ' ';
    cout << '\n';
    return 0;
}
