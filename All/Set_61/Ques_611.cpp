// Trapping Rain Water

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int &height : heights) cin >> height;
    int left = 0, right = n - 1, leftMax = 0, rightMax = 0, water = 0;
    while (left <= right) {
        if (heights[left] <= heights[right]) {
            leftMax = max(leftMax, heights[left]);
            water += leftMax - heights[left++];
        } else {
            rightMax = max(rightMax, heights[right]);
            water += rightMax - heights[right--];
        }
    }
    cout << water << '\n';
    return 0;
}
