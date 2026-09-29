// Product of Array Except Self

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n), answer(n, 1);
    for (int &value : numbers) cin >> value;
    int product = 1;
    for (int i = 0; i < n; i++) {
        answer[i] = product;
        product *= numbers[i];
    }
    product = 1;
    for (int i = n - 1; i >= 0; i--) {
        answer[i] *= product;
        product *= numbers[i];
    }
    for (int value : answer) cout << value << ' ';
    cout << '\n';
    return 0;
}

