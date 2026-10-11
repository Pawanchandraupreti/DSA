// Implement Queue Using Two Stacks

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> first, second;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        first.push(x);
    }

    while (!first.empty()) {
        second.push(first.top());
        first.pop();
    }
    while (!second.empty()) {
        cout << second.top() << ' ';
        second.pop();
    }
    cout << '\n';
    return 0;
}
