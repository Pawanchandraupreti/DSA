// Count Words with a Given Prefix

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int next[26]{};
    int cnt = 0;
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<Node> tr(1);

    while (n--) {
        string s;
        cin >> s;
        int u = 0;
        for (char c : s) {
            int x = c - 'a';
            if (!tr[u].next[x]) {
                tr[u].next[x] = tr.size();
                tr.push_back(Node());
            }
            u = tr[u].next[x];
            tr[u].cnt++;
        }
    }

    while (q--) {
        string s;
        cin >> s;
        int u = 0;
        bool ok = true;
        for (char c : s) {
            int x = c - 'a';
            if (!tr[u].next[x]) {
                ok = false;
                break;
            }
            u = tr[u].next[x];
        }
        cout << (ok ? tr[u].cnt : 0) << '\n';
    }
    return 0;
}
