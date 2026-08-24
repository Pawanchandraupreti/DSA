// Weighted Interval Scheduling

#include <bits/stdc++.h>
using namespace std;

struct Job {
    int start;
    int finish;
    int profit;
};

int maximumProfit(vector<Job> jobs) {
    sort(jobs.begin(), jobs.end(), [](const Job& first, const Job& second) {
        return first.finish < second.finish;
    });

    vector<int> dp(jobs.size() + 1, 0);
    for (int index = 1; index <= (int)jobs.size(); ++index) {
        int previous = 0;
        int left = 0;
        int right = index - 2;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (jobs[middle].finish <= jobs[index - 1].start) {
                previous = middle + 1;
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        dp[index] = max(dp[index - 1], jobs[index - 1].profit + dp[previous]);
    }

    return dp.back();
}

int main() {
    int n;
    cin >> n;

    vector<Job> jobs(n);
    for (Job& job : jobs) cin >> job.start >> job.finish >> job.profit;

    cout << maximumProfit(jobs);
    return 0;
}
