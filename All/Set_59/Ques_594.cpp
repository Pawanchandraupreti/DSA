// Add Strings

#include <bits/stdc++.h>
using namespace std;

int main() {
    string first, second, answer;
    cin >> first >> second;
    int i = first.size() - 1, j = second.size() - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += first[i--] - '0';
        if (j >= 0) sum += second[j--] - '0';
        answer.push_back('0' + sum % 10);
        carry = sum / 10;
    }
    reverse(answer.begin(), answer.end());
    cout << answer << '\n';
    return 0;
}

