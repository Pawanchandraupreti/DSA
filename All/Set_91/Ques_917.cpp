// Majority Element

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cand = 0, votes = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (votes == 0) cand = x;
        votes += (x == cand ? 1 : -1);
    }
    cout << cand << '\n';
    return 0;
}

