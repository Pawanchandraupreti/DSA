// Reverse Array as a Linked List

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    reverse(a.begin(), a.end());
    for (int x : a) cout << x << ' ';
    cout << '\n';
    return 0;
}
