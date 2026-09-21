// Jump Game

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int reach = 0;
    for (int i = 0; i < n; i++) {
        if (i > reach) {
            cout << "false\n";
            return 0;
        }
        reach = max(reach, i + a[i]);
    }

    cout << "true\n";
    return 0;
}


