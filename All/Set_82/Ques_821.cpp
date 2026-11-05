// Minimum Moves to Equal Array

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int minimum = *min_element(a.begin(), a.end());
    long long moves = 0;
    for (int x : a) moves += x - minimum;
    cout << moves << '\n';
    return 0;
}
