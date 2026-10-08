// Find Duplicate Number

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n + 1);
    for (int &value : numbers) cin >> value;
    int slow = numbers[0], fast = numbers[numbers[0]];
    while (slow != fast) {
        slow = numbers[slow];
        fast = numbers[numbers[fast]];
    }
    slow = 0;
    while (slow != fast) {
        slow = numbers[slow];
        fast = numbers[fast];
    }
    cout << slow << '\n';
    return 0;
}


