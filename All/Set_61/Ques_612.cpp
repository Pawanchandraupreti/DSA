// Jump Game

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> jumps(n);
    for (int &jump : jumps) cin >> jump;
    int farthest = 0;
    for (int i = 0; i < n && i <= farthest; i++) {
        farthest = max(farthest, i + jumps[i]);
    }
    cout << (farthest >= n - 1 ? "true" : "false") << '\n';
    return 0;
}


