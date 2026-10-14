// Single Number

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, answer = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        answer ^= x;
    }
    cout << answer << '\n';
    return 0;
}
