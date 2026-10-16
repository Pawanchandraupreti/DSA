// Candy Distribution

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> rating(n), candy(n, 1);
    for (int &x : rating) cin >> x;

    for (int i = 1; i < n; i++) {
        if (rating[i] > rating[i - 1]) candy[i] = candy[i - 1] + 1;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (rating[i] > rating[i + 1]) candy[i] = max(candy[i], candy[i + 1] + 1);
    }
    cout << accumulate(candy.begin(), candy.end(), 0) << '\n';
    return 0;
}
