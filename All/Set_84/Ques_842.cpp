// Next Greater Number with Same Digits

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    if (!next_permutation(s.begin(), s.end())) cout << -1 << '\n';
    else cout << s << '\n';
    return 0;
}
