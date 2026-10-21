// Count Arithmetic Slices

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    long long current = 0, answer = 0;
    for (int i = 2; i < n; i++) {
        if (a[i] - a[i - 1] == a[i - 1] - a[i - 2]) current++;
        else current = 0;
        answer += current;
    }
    cout << answer << '\n';
    return 0;
}
