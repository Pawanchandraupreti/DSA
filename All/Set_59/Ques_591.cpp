// Move Zeroes

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int &value : numbers) cin >> value;
    int position = 0;
    for (int value : numbers) if (value != 0) numbers[position++] = value;
    while (position < n) numbers[position++] = 0;
    for (int value : numbers) cout << value << ' ';
    cout << '\n';
    return 0;
}


