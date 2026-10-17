// Longest Zero Sum Subarray

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> first;
    first[0] = -1;
    int prefix = 0, answer = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        prefix += x;
        if (first.count(prefix)) answer = max(answer, i - first[prefix]);
        else first[prefix] = i;
    }
    cout << answer << '\n';
    return 0;
}
