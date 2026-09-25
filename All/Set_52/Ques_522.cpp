// Container With Most Water

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> height(n);
    for (int &x : height) cin >> x;

    int left = 0, right = n - 1;
    long long answer = 0;
    while (left < right) {
        answer = max(answer, 1LL * min(height[left], height[right]) * (right - left));
        if (height[left] < height[right]) left++;
        else right--;
    }

    cout << answer << '\n';
    return 0;
}
