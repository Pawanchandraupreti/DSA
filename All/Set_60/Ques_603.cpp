// Longest Increasing Subsequence

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n), length(n, 1);
    for (int &value : numbers) cin >> value;
    int answer = n ? 1 : 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (numbers[j] < numbers[i]) length[i] = max(length[i], length[j] + 1);
        }
        answer = max(answer, length[i]);
    }
    cout << answer << '\n';
    return 0;
}

