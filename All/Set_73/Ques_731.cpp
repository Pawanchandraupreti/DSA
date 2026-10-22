// Minimum Arrows to Burst Balloons

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> balloons(n);
    for (auto &[start, end] : balloons) cin >> start >> end;
    sort(balloons.begin(), balloons.end(), [](auto a, auto b) { return a.second < b.second; });

    int arrows = 0, position = INT_MIN;
    for (auto [start, end] : balloons) {
        if (arrows == 0 || start > position) {
            arrows++;
            position = end;
        }
    }
    cout << arrows << '\n';
    return 0;
}
