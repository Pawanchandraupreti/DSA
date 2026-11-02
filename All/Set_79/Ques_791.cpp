// Minimum Cost to Hire K Workers

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<double, int>> workers;
    for (int i = 0; i < n; i++) {
        int quality, wage;
        cin >> quality >> wage;
        workers.push_back({(double)wage / quality, quality});
    }
    sort(workers.begin(), workers.end());
    priority_queue<int> heap;
    int qualitySum = 0;
    double answer = 1e18;
    for (auto [ratio, quality] : workers) {
        heap.push(quality);
        qualitySum += quality;
        if ((int)heap.size() > k) {
            qualitySum -= heap.top();
            heap.pop();
        }
        if ((int)heap.size() == k) answer = min(answer, ratio * qualitySum);
    }
    cout << fixed << setprecision(5) << answer << '\n';
    return 0;
}
