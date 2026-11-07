// Maximum Score from Words

#include <bits/stdc++.h>
using namespace std;

int solve(int index, vector<string> &words, vector<int> &letters, vector<int> &score) {
    if (index == (int)words.size()) return 0;
    int answer = solve(index + 1, words, letters, score);
    vector<int> used(26);
    int value = 0;
    bool possible = true;
    for (char ch : words[index]) {
        int letter = ch - 'a';
        used[letter]++;
        value += score[letter];
        if (used[letter] > letters[letter]) possible = false;
    }
    if (possible) {
        for (int i = 0; i < 26; i++) letters[i] -= used[i];
        answer = max(answer, value + solve(index + 1, words, letters, score));
        for (int i = 0; i < 26; i++) letters[i] += used[i];
    }
    return answer;
}

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (string &word : words) cin >> word;
    vector<int> letters(26), score(26);
    for (int &x : letters) cin >> x;
    for (int &x : score) cin >> x;
    cout << solve(0, words, letters, score) << '\n';
    return 0;
}
