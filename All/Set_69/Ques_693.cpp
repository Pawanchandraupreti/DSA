// Target Sum Ways

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    unordered_map<int, long long> ways;
    ways[0] = 1;
    for (int x : a) {
        unordered_map<int, long long> next;
        for (auto [sum, count] : ways) {
            next[sum + x] += count;
            next[sum - x] += count;
        }
        ways = move(next);
    }
    cout << ways[target] << '\n';
    return 0;
}
