// First and Last Position in a Sorted Array

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int &v : a) cin >> v;

    auto first = lower_bound(a.begin(), a.end(), x);
    auto last = upper_bound(a.begin(), a.end(), x);

    if (first == a.end() || *first != x) {
        cout << "-1 -1\n";
    } else {
        cout << first - a.begin() << ' ' << last - a.begin() - 1 << '\n';
    }
    return 0;
}
