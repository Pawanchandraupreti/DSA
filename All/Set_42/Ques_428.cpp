// Nth Catalan Number with Arbitrary Precision

#include <bits/stdc++.h>
using namespace std;

vector<int> multiply(const vector<int>& number, int multiplier) {
    vector<int> result;
    long long carry = 0;
    for (int digit : number) {
        long long value = 1LL * digit * multiplier + carry;
        result.push_back((int)(value % 10));
        carry = value / 10;
    }
    while (carry) {
        result.push_back((int)(carry % 10));
        carry /= 10;
    }
    return result;
}

vector<int> divide(const vector<int>& number, int divisor) {
    vector<int> result(number.size());
    long long remainder = 0;
    for (int i = (int)number.size() - 1; i >= 0; --i) {
        long long value = remainder * 10 + number[i];
        result[i] = (int)(value / divisor);
        remainder = value % divisor;
    }
    while (result.size() > 1 && result.back() == 0) result.pop_back();
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> answer = {1};
    for (int i = 0; i < n; ++i) {
        answer = multiply(answer, 2 * (2 * i + 1));
        answer = divide(answer, i + 2);
    }
    for (auto it = answer.rbegin(); it != answer.rend(); ++it) cout << *it;
    return 0;
}


