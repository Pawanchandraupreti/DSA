// Task Scheduler

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cooldown;
    cin >> n >> cooldown;
    vector<int> tasks(n);
    for (int &task : tasks) cin >> task;
    vector<int> frequency(101);
    for (int task : tasks) frequency[task]++;
    int highest = *max_element(frequency.begin(), frequency.end());
    int same = count(frequency.begin(), frequency.end(), highest);
    int slots = (highest - 1) * (cooldown + 1) + same;
    cout << max(n, slots) << '\n';
    return 0;
}
