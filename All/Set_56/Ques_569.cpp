// Intersection of Two Arrays

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<int> first, answer;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        first.insert(value);
    }
    for (int i = 0; i < m; i++) {
        int value;
        cin >> value;
        if (first.count(value)) answer.insert(value);
    }
    for (int value : answer) cout << value << ' ';
    cout << '\n';
    return 0;
}


