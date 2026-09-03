// Job Scheduling with Deadlines and Profits

#include <bits/stdc++.h>
using namespace std;

struct Job {
    int deadline, profit;
};

int main() {
    int n;
    cin >> n;
    vector<Job> jobs(n);
    int maxDeadline = 0;
    for (Job& job : jobs) {
        cin >> job.deadline >> job.profit;
        maxDeadline = max(maxDeadline, job.deadline);
    }
    sort(jobs.begin(), jobs.end(), [](const Job& first, const Job& second) {
        return first.profit > second.profit;
    });

    vector<int> parent(maxDeadline + 1);
    iota(parent.begin(), parent.end(), 0);
    function<int(int)> findSlot = [&](int slot) {
        return parent[slot] == slot ? slot : parent[slot] = findSlot(parent[slot]);
    };

    int completed = 0, totalProfit = 0;
    for (const Job& job : jobs) {
        int slot = findSlot(min(job.deadline, maxDeadline));
        if (slot > 0) {
            ++completed;
            totalProfit += job.profit;
            parent[slot] = findSlot(slot - 1);
        }
    }
    cout << completed << ' ' << totalProfit;
    return 0;
}
