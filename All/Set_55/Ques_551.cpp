// Two Sum

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> numbers(n);
    unordered_map<int, int> seen;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        int need = target - numbers[i];
        if (seen.count(need)) {
            cout << seen[need] << ' ' << i << '\n';
            return 0;
        }
        seen[numbers[i]] = i;
    }
    cout << -1 << '\n';
    return 0;
}
