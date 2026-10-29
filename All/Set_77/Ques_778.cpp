// Minimum Window Subsequence Length

#include <bits/stdc++.h>
using namespace std;

int main() {
    string source, target;
    cin >> source >> target;
    int answer = source.size() + 1;
    for (int start = 0; start < (int)source.size(); start++) {
        int index = start;
        for (char ch : target) {
            while (index < (int)source.size() && source[index] != ch) index++;
            if (index == (int)source.size()) break;
            index++;
        }
        if (index <= (int)source.size()) answer = min(answer, index - start);
    }
    cout << (answer == (int)source.size() + 1 ? 0 : answer) << '\n';
    return 0;
}


