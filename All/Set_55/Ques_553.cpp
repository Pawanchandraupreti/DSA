// Majority Element

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, candidate = 0, count = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        if (count == 0) candidate = value;
        count += value == candidate ? 1 : -1;
    }
    cout << candidate << '\n';
    return 0;
}
