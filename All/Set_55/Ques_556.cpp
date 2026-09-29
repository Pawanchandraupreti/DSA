// Longest Consecutive Sequence

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<int> numbers;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        numbers.insert(value);
    }
    int longest = 0;
    for (int value : numbers) {
        if (!numbers.count(value - 1)) {
            int current = value, length = 1;
            while (numbers.count(current + 1)) {
                current++;
                length++;
            }
            longest = max(longest, length);
        }
    }
    cout << longest << '\n';
    return 0;
}
