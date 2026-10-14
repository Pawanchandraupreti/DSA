// Find Missing Number

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int answer = n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        answer ^= i ^ x;
    }
    cout << answer << '\n';
    return 0;
}
