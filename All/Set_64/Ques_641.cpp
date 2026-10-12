// First and Last Position of Target

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    auto first = lower_bound(a.begin(), a.end(), target);
    if (first == a.end() || *first != target) {
        cout << "-1 -1\n";
        return 0;
    }
    auto last = upper_bound(a.begin(), a.end(), target) - 1;
    cout << first - a.begin() << ' ' << last - a.begin() << '\n';
    return 0;
}
