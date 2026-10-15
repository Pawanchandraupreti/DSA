// Longest Increasing Subsequence

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> tails;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto position = lower_bound(tails.begin(), tails.end(), x);
        if (position == tails.end()) tails.push_back(x);
        else *position = x;
    }
    cout << tails.size() << '\n';
    return 0;
}


