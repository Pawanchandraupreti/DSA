// Min Stack

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> values, minimums;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        values.push(value);
        if (minimums.empty() || value <= minimums.top()) minimums.push(value);
    }
    cout << minimums.top() << '\n';
    return 0;
}

