// Happy Number

#include <bits/stdc++.h>
using namespace std;

int main() {
    int number;
    cin >> number;
    if (number == 0) {
        cout << "false\n";
        return 0;
    }
    set<int> seen;
    while (number != 1 && !seen.count(number)) {
        seen.insert(number);
        int sum = 0;
        while (number > 0) {
            int digit = number % 10;
            sum += digit * digit;
            number /= 10;
        }
        number = sum;
    }
    cout << (number == 1 ? "true" : "false") << '\n';
    return 0;
}
