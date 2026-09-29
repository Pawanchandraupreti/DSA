// Rotate Array

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, steps;
    cin >> n >> steps;
    vector<int> numbers(n);
    for (int &value : numbers) cin >> value;
    steps %= n;
    rotate(numbers.begin(), numbers.end() - steps, numbers.end());
    for (int value : numbers) cout << value << ' ';
    cout << '\n';
    return 0;
}

