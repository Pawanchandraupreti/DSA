// Sort Colors

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> colors(n);
    for (int &color : colors) cin >> color;
    int left = 0, current = 0, right = n - 1;
    while (current <= right) {
        if (colors[current] == 0) swap(colors[left++], colors[current++]);
        else if (colors[current] == 2) swap(colors[current], colors[right--]);
        else current++;
    }
    for (int color : colors) cout << color << ' ';
    cout << '\n';
    return 0;
}

