// Koko Eating Bananas

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> piles(n);
    for (int &x : piles) cin >> x;
    int h;
    cin >> h;

    int low = 1, high = *max_element(piles.begin(), piles.end());
    while (low < high) {
        int mid = (low + high) / 2;
        long long hours = 0;
        for (int x : piles) hours += (x + mid - 1) / mid;
        if (hours <= h) high = mid;
        else low = mid + 1;
    }

    cout << low << '\n';
    return 0;
}


