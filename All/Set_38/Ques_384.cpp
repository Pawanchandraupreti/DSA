// Sliding Window Maximum

#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < (int)nums.size(); ++i) {
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> result = maxSlidingWindow(nums, k);
    for (int value : result) {
        cout << value << ' ';
    }

    return 0;
}


