// Single Number

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n) || n < 0) return 0;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        answer ^= x;
    }

    cout << answer << '\n';
    return 0;
}
