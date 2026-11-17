// House Robber

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long skip = 0, take = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        long long next = max(skip, take);
        take = skip + x;
        skip = next;
    }
    cout << max(skip, take) << '\n';
    return 0;
}
