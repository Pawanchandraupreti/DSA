// Minimum Deletions for Unique Frequencies

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> frequency(26);
    for (char ch : s) frequency[ch - 'a']++;
    sort(frequency.rbegin(), frequency.rend());
    int answer = 0, used = frequency[0];
    for (int count : frequency) {
        int allowed = min(count, max(0, used - 1));
        answer += count - allowed;
        used = allowed;
    }
    cout << answer << '\n';
    return 0;
}

