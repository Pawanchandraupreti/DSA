// Minimum Speed to Arrive on Time

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double hour;
    cin >> n >> hour;
    vector<int> distance(n);
    for (int &x : distance) cin >> x;
    int left = 1, right = 10000000, answer = -1;
    while (left <= right) {
        int speed = left + (right - left) / 2;
        double time = 0;
        for (int i = 0; i < n; i++) time += i + 1 == n ? (double)distance[i] / speed : ceil((double)distance[i] / speed);
        if (time <= hour) answer = speed, right = speed - 1;
        else left = speed + 1;
    }
    cout << answer << '\n';
    return 0;
}
