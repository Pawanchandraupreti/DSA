// Find All Duplicates in Array

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), answer;
    for (int &x : a) cin >> x;
    for (int x : a) {
        int index = abs(x) - 1;
        if (a[index] < 0) answer.push_back(abs(x));
        else a[index] = -a[index];
    }
    sort(answer.begin(), answer.end());
    for (int x : answer) cout << x << ' ';
    cout << '\n';
    return 0;
}
