// Minimum Cost to Partition an Array

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, groups;
    cin >> n >> groups;
    vector<long long> prefix(n + 1);
    for (int i = 1; i <= n; i++) {
        int value;
        cin >> value;
        prefix[i] = prefix[i - 1] + value;
    }
    const long long infinity = (1LL << 62);
    vector<long long> previous(n + 1, infinity), current(n + 1);
    previous[0] = 0;
    for (int group = 1; group <= groups; group++) {
        fill(current.begin(), current.end(), infinity);
        for (int right = group; right <= n; right++)
            for (int left = group - 1; left < right; left++)
                if (previous[left] != infinity)
                    current[right] = min(current[right], previous[left] + (prefix[right] - prefix[left]) * (prefix[right] - prefix[left]));
        previous.swap(current);
    }
    cout << previous[n] << '\n';
    return 0;
}
