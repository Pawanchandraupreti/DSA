// Subarray Sum Equals K

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    unordered_map<int, int> frequency;
    frequency[0] = 1;
    int sum = 0, answer = 0;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        sum += value;
        answer += frequency[sum - target];
        frequency[sum]++;
    }
    cout << answer << '\n';
    return 0;
}
