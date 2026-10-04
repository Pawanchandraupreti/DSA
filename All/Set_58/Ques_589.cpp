// Longest Palindromic Substring

#include <bits/stdc++.h>
using namespace std;

int main() {
    string text;
    cin >> text;
    string answer;
    for (int center = 0; center < (int)text.size(); center++) {
        for (int side = 0; center - side >= 0 && center + side < (int)text.size() && text[center - side] == text[center + side]; side++) {
            if (2 * side + 1 > (int)answer.size()) answer = text.substr(center - side, 2 * side + 1);
        }
        for (int side = 0; center - side >= 0 && center + side + 1 < (int)text.size() && text[center - side] == text[center + side + 1]; side++) {
            if (2 * side + 2 > (int)answer.size()) answer = text.substr(center - side, 2 * side + 2);
        }
    }
    cout << answer << '\n';
    return 0;
}

