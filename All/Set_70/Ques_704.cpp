// Partition Labels

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> last(26);
    for (int i = 0; i < (int)s.size(); i++) last[s[i] - 'a'] = i;

    int start = 0, end = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        end = max(end, last[s[i] - 'a']);
        if (i == end) {
            cout << end - start + 1 << ' ';
            start = i + 1;
        }
    }
    cout << '\n';
    return 0;
}
