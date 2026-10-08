// Largest Rectangle in Histogram

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> heights(n), stackIndices;
    for (int &height : heights) cin >> height;
    int answer = 0;
    for (int i = 0; i <= n; i++) {
        int current = i == n ? 0 : heights[i];
        while (!stackIndices.empty() && current < heights[stackIndices.back()]) {
            int height = heights[stackIndices.back()];
            stackIndices.pop_back();
            int width = stackIndices.empty() ? i : i - stackIndices.back() - 1;
            answer = max(answer, height * width);
        }
        stackIndices.push_back(i);
    }
    cout << answer << '\n';
    return 0;
}
