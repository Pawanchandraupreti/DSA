// House Robber

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int previousTwo = 0, previousOne = 0;
    for (int i = 0; i < n; i++) {
        int money;
        cin >> money;
        int best = max(previousOne, previousTwo + money);
        previousTwo = previousOne;
        previousOne = best;
    }
    cout << previousOne << '\n';
    return 0;
}
