// Array Nesting Length

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int answer = 0;
    for (int start = 0; start < n; start++) {
        int current = start, length = 0;
        while (a[current] != -1) {
            int next = a[current];
            a[current] = -1;
            current = next;
            length++;
        }
        answer = max(answer, length);
    }
    cout << answer << '\n';
    return 0;
}
