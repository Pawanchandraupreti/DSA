// Pascal Triangle Row

#include <bits/stdc++.h>
using namespace std;

int main() {
    int row;
    cin >> row;
    vector<long long> values(row + 1, 1);
    for (int index = 1; index < row; index++) {
        values[index] = values[index - 1] * (row - index + 1) / index;
    }
    for (long long value : values) cout << value << ' ';
    cout << '\n';
    return 0;
}
