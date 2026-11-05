// Minimum Time Difference

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> minutes(n);
    for (int i = 0; i < n; i++) {
        string time;
        cin >> time;
        minutes[i] = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));
    }
    sort(minutes.begin(), minutes.end());
    int answer = 1440 - minutes.back() + minutes.front();
    for (int i = 1; i < n; i++) answer = min(answer, minutes[i] - minutes[i - 1]);
    cout << answer << '\n';
    return 0;
}
