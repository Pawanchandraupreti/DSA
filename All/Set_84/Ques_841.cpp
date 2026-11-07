// Maximum Swap

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> last(10, -1);
    for (int i = 0; i < (int)s.size(); i++) last[s[i] - '0'] = i;
    for (int i = 0; i < (int)s.size(); i++) {
        for (int digit = 9; digit > s[i] - '0'; digit--) if (last[digit] > i) {
            swap(s[i], s[last[digit]]);
            cout << s << '\n';
            return 0;
        }
    }
    cout << s << '\n';
    return 0;
}
