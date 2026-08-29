// Longest Increasing Subsequence with Binary Search

#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(const vector<int>& numbers) {
    vector<int> subsequence;

    for (int number : numbers) {
        auto position = lower_bound(subsequence.begin(), subsequence.end(), number);
        if (position == subsequence.end()) {
            subsequence.push_back(number);
        } else {
            *position = number;
        }
    }

    return (int)subsequence.size();
}

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int& number : numbers) cin >> number;

    cout << lengthOfLIS(numbers);
    return 0;
}
