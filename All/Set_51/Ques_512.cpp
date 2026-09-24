// Intersection of Two Arrays

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    unordered_set<int> values;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        values.insert(x);
    }

    set<int> answer;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (values.count(x)) answer.insert(x);
    }

    for (int x : answer) cout << x << ' ';
    cout << '\n';
    return 0;
}
