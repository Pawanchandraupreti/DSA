// Remove Duplicate Letters

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> last(26);
    vector<bool> used(26);
    for (int i = 0; i < (int)s.size(); i++) last[s[i] - 'a'] = i;

    string answer;
    for (int i = 0; i < (int)s.size(); i++) {
        int index = s[i] - 'a';
        if (used[index]) continue;
        while (!answer.empty() && answer.back() > s[i] && last[answer.back() - 'a'] > i) {
            used[answer.back() - 'a'] = false;
            answer.pop_back();
        }
        answer += s[i];
        used[index] = true;
    }
    cout << answer << '\n';
    return 0;
}
