// Add Binary

#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int i = a.size() - 1, j = b.size() - 1, carry = 0;
    string answer;
    while (i >= 0 || j >= 0 || carry) {
        int x = (i >= 0 ? a[i--] - '0' : 0);
        int y = (j >= 0 ? b[j--] - '0' : 0);
        int sum = x + y + carry;
        answer.push_back(char('0' + (sum % 2)));
        carry = sum / 2;
    }
    reverse(answer.begin(), answer.end());
    cout << answer << '\n';
    return 0;
}
