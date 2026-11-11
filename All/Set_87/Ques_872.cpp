// K-th Lexicographically Smallest Distinct Substring

#include <bits/stdc++.h>
using namespace std;

int main() {
    string text;
    long long k;
    cin >> text >> k;
    int n = text.size();
    vector<int> suffix(n), rank(n), nextRank(n);
    iota(suffix.begin(), suffix.end(), 0);
    for (int i = 0; i < n; i++) rank[i] = text[i];
    for (int length = 1;; length <<= 1) {
        sort(suffix.begin(), suffix.end(), [&](int a, int b) {
            if (rank[a] != rank[b]) return rank[a] < rank[b];
            int ra = a + length < n ? rank[a + length] : -1;
            int rb = b + length < n ? rank[b + length] : -1;
            return ra < rb;
        });
        nextRank[suffix[0]] = 0;
        for (int i = 1; i < n; i++) {
            int a = suffix[i - 1], b = suffix[i];
            bool different = rank[a] != rank[b];
            int ra = a + length < n ? rank[a + length] : -1;
            int rb = b + length < n ? rank[b + length] : -1;
            nextRank[b] = nextRank[a] + (different || ra != rb);
        }
        rank = nextRank;
        if (rank[suffix.back()] == n - 1) break;
    }
    vector<int> lcp(n);
    for (int i = 0, matched = 0; i < n; i++) {
        int position = rank[i];
        if (position == 0) continue;
        int other = suffix[position - 1];
        while (i + matched < n && other + matched < n &&
               text[i + matched] == text[other + matched]) matched++;
        lcp[position] = matched;
        if (matched) matched--;
    }
    for (int i = 0; i < n; i++) {
        long long choices = n - suffix[i] - lcp[i];
        if (k > choices) k -= choices;
        else {
            cout << text.substr(suffix[i], lcp[i] + k) << '\n';
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}
