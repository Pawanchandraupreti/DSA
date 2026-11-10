// Longest Subarray with Bounded Difference

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, limit;
    cin >> n >> limit;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    deque<int> minimum, maximum;
    int left = 0, answer = 0;
    for (int right = 0; right < n; right++) {
        while (!minimum.empty() && a[minimum.back()] >= a[right]) minimum.pop_back();
        while (!maximum.empty() && a[maximum.back()] <= a[right]) maximum.pop_back();
        minimum.push_back(right); maximum.push_back(right);
        while (a[maximum.front()] - a[minimum.front()] > limit) {
            if (minimum.front() == left) minimum.pop_front();
            if (maximum.front() == left) maximum.pop_front();
            left++;
        }
        answer = max(answer, right - left + 1);
    }
    cout << answer << '\n';
    return 0;
}

