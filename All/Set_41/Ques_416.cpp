// Suffix Array Construction

#include <bits/stdc++.h>
using namespace std;

vector<int> buildSuffixArray(const string& str) {
    int n = (int)str.length();
    vector<int> suffixes(n);
    for (int i = 0; i < n; ++i) {
        suffixes[i] = i;
    }

    vector<int> rank(n), tempRank(n);
    for (int i = 0; i < n; ++i) {
        rank[i] = str[i];
    }

    for (int k = 1; k < n; k *= 2) {
        auto compare = [&](int a, int b) {
            if (rank[a] != rank[b]) return rank[a] < rank[b];
            int rankA = (a + k < n) ? rank[a + k] : -1;
            int rankB = (b + k < n) ? rank[b + k] : -1;
            return rankA < rankB;
        };

        sort(suffixes.begin(), suffixes.end(), compare);

        tempRank[suffixes[0]] = 0;
        for (int i = 1; i < n; ++i) {
            tempRank[suffixes[i]] = tempRank[suffixes[i - 1]];
            if (compare(suffixes[i - 1], suffixes[i])) {
                tempRank[suffixes[i]]++;
            }
        }
        rank = tempRank;
    }
    return suffixes;
}

int main() {
    string str;
    cin >> str;

    vector<int> suffixArray = buildSuffixArray(str);
    for (int index : suffixArray) {
        cout << index << ' ';
    }
    return 0;
}
