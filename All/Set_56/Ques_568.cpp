// Climbing Stairs

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long previous = 1, current = 1;
    for (int step = 2; step <= n; step++) {
        long long next = previous + current;
        previous = current;
        current = next;
    }
    cout << current << '\n';
    return 0;
}


