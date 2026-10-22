// Task Scheduler Minimum Time

#include <bits/stdc++.h>
using namespace std;

int main() {
    string tasks;
    int cooldown;
    cin >> tasks >> cooldown;
    vector<int> frequency(26);
    for (char task : tasks) frequency[task - 'A']++;
    int highest = *max_element(frequency.begin(), frequency.end());
    int countHighest = count(frequency.begin(), frequency.end(), highest);
    cout << max((int)tasks.size(), (highest - 1) * (cooldown + 1) + countHighest) << '\n';
    return 0;
}
