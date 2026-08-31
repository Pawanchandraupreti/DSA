// Largest Rectangle in Skyline

#include <bits/stdc++.h>
using namespace std;

long long largestRectangleArea(const vector<int>& heights) {
    stack<int> indices;
    long long maxArea = 0;

    for (int index = 0; index < (int)heights.size(); ++index) {
        while (!indices.empty() && heights[indices.top()] > heights[index]) {
            int height = heights[indices.top()];
            indices.pop();
            int width = indices.empty() ? index : index - indices.top() - 1;
            maxArea = max(maxArea, (long long)height * width);
        }
        indices.push(index);
    }

    while (!indices.empty()) {
        int height = heights[indices.top()];
        indices.pop();
        int width = indices.empty() ? (int)heights.size() : (int)heights.size() - indices.top() - 1;
        maxArea = max(maxArea, (long long)height * width);
    }

    return maxArea;
}

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int& height : heights) cin >> height;

    cout << largestRectangleArea(heights);
    return 0;
}


