// Container With Most Water

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int &x : h) cin >> x;

    int left = 0, right = n - 1, answer = 0;
    while (left < right) {
        answer = max(answer, min(h[left], h[right]) * (right - left));
        if (h[left] <= h[right]) left++;
        else right--;
    }
    cout << answer << '\n';
    return 0;
}
