// Power of Two

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long number;
    cin >> number;
    cout << (number > 0 && (number & (number - 1)) == 0 ? "true" : "false") << '\n';
    return 0;
}
