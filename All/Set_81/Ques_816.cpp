// String Compression Length

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int answer = 0;
    for (int i = 0; i < (int)s.size();) {
        int j = i;
        while (j < (int)s.size() && s[j] == s[i]) j++;
        answer += 1 + (j - i > 1 ? to_string(j - i).size() : 0);
        i = j;
    }
    cout << answer << '\n';
    return 0;
}
