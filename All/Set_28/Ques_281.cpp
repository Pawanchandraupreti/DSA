// Weighted interval scheduling with reconstruction

#include <bits/stdc++.h>
using namespace std;

struct Job {
    long long s, e, w;
    int id;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<Job> jobs(n);
    for (int i = 0; i < n; ++i) {
        cin >> jobs[i].s >> jobs[i].e >> jobs[i].w;
        jobs[i].id = i + 1;
    }

    sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
        if (a.e != b.e) return a.e < b.e;
        return a.s < b.s;
    });

    vector<long long> ends(n);
    for (int i = 0; i < n; ++i) ends[i] = jobs[i].e;

    vector<long long> dp(n + 1, 0);
    vector<int> take(n + 1, 0), prevIdx(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int j = upper_bound(ends.begin(), ends.end(), jobs[i - 1].s) - ends.begin();
        long long pick = jobs[i - 1].w + dp[j];
        long long skip = dp[i - 1];
        if (pick > skip) {
            dp[i] = pick;
            take[i] = 1;
            prevIdx[i] = j;
        } else {
            dp[i] = skip;
            take[i] = 0;
            prevIdx[i] = i - 1;
        }
    }

    vector<int> chosen;
    for (int i = n; i > 0;) {
        if (take[i]) {
            chosen.push_back(jobs[i - 1].id);
            i = prevIdx[i];
        } else {
            --i;
        }
    }
    reverse(chosen.begin(), chosen.end());

    cout << dp[n] << '\n' << chosen.size();
    for (int x : chosen) cout << ' ' << x;
    return 0;
}


