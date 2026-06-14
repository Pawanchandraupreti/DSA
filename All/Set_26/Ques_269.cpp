// Maximum subarray XOR using a binary trie of prefix XORs

#include <bits/stdc++.h>
using namespace std;

struct Trie {
    struct Node { int child[2] = {-1, -1}; };
    vector<Node> t{Node()};

    void insert(int x) {
        int node = 0;
        for (int b = 31; b >= 0; --b) {
            int bit = (x >> b) & 1;
            if (t[node].child[bit] == -1) {
                t[node].child[bit] = (int)t.size();
                t.push_back(Node());
            }
            node = t[node].child[bit];
        }
    }

    int best(int x) const {
        int node = 0, ans = 0;
        for (int b = 31; b >= 0; --b) {
            int bit = (x >> b) & 1;
            int want = bit ^ 1;
            if (t[node].child[want] != -1) {
                ans |= (1 << b);
                node = t[node].child[want];
            } else {
                node = t[node].child[bit];
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    Trie trie;
    trie.insert(0);
    int pref = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        pref ^= x;
        ans = max(ans, trie.best(pref));
        trie.insert(pref);
    }
    cout << ans;
    return 0;
}


