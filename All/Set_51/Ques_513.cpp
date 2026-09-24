// Sort Colors

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int zero = 0, one = 0, two = n - 1;
    while (one <= two) {
        if (a[one] == 0) swap(a[zero++], a[one++]);
        else if (a[one] == 2) swap(a[one], a[two--]);
        else one++;
    }

    for (int x : a) cout << x << ' ';
    cout << '\n';
    return 0;
}
