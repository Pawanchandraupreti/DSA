// Kth Largest Element

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> numbers(n);
    for (int &value : numbers) cin >> value;
    nth_element(numbers.begin(), numbers.end() - k, numbers.end());
    cout << numbers[n - k] << '\n';
    return 0;
}
