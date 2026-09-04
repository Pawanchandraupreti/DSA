// Maximum Depth of Nested Parentheses

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int curr = 0, maxDepth = 0;
    for (char c : s) {
        if (c == '(') {
            curr++;
            maxDepth = max(maxDepth, curr);
        } else if (c == ')') {
            curr--;
        }
    }
    
    cout << maxDepth;
    return 0;
}
