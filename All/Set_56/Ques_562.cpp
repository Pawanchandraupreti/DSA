// Contains Duplicate

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> seen;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (!seen.insert(x).second) {
            cout << "true\n";
            return 0;
        }
    }
    cout << "false\n";
    return 0;
}
