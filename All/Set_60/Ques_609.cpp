// Minimum Window Substring Length

#include <bits/stdc++.h>
using namespace std;

int main() {
    string text, pattern;
    cin >> text >> pattern;
    vector<int> need(256);
    for (char letter : pattern) need[(unsigned char)letter]++;
    int missing = pattern.size(), left = 0, answer = INT_MAX;
    for (int right = 0; right < (int)text.size(); right++) {
        if (need[(unsigned char)text[right]]-- > 0) missing--;
        while (missing == 0) {
            answer = min(answer, right - left + 1);
            if (++need[(unsigned char)text[left++]] > 0) missing++;
        }
    }
    cout << (answer == INT_MAX ? 0 : answer) << '\n';
    return 0;
}


