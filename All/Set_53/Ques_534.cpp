// Minimum Platforms

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arrival(n), departure(n);
    for (int &x : arrival) cin >> x;
    for (int &x : departure) cin >> x;
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int i = 0, j = 0, current = 0, answer = 0;
    while (i < n) {
        if (arrival[i] <= departure[j]) {
            current++;
            answer = max(answer, current);
            i++;
        } else {
            current--;
            j++;
        }
    }

    cout << answer << '\n';
    return 0;
}
