// Daily Temperatures

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> temperatures(n), answer(n), pending;
    for (int &temperature : temperatures) cin >> temperature;
    for (int day = 0; day < n; day++) {
        while (!pending.empty() && temperatures[day] > temperatures[pending.back()]) {
            int previous = pending.back();
            pending.pop_back();
            answer[previous] = day - previous;
        }
        pending.push_back(day);
    }
    for (int value : answer) cout << value << ' ';
    cout << '\n';
    return 0;
}


