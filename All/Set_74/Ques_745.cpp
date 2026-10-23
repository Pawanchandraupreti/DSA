// Maximum Chunks to Make Sorted

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int answer = 0, maximum = 0;
    for (int i = 0; i < n; i++) {
        maximum = max(maximum, a[i]);
        if (maximum == i) answer++;
    }
    cout << answer << '\n';
    return 0;
}
