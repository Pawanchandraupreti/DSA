// Longest Consecutive Sequence

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<int> values;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        values.insert(x);
    }

    int answer = 0;
    for (int x : values) {
        if (!values.count(x - 1)) {
            int current = x;
            int length = 1;
            while (values.count(current + 1)) {
                current++;
                length++;
            }
            answer = max(answer, length);
        }
    }

    cout << answer << '\n';
    return 0;
}
