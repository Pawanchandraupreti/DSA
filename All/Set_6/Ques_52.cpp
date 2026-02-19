// Trapping Rain Water (Prefix Max Technique)

#include <iostream>
using namespace std;

int main() {
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = 12;

    int leftMax[12], rightMax[12];
    leftMax[0] = height[0];

    for (int i = 1; i < n; i++)
        leftMax[i] = max(leftMax[i - 1], height[i]);

    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
        rightMax[i] = max(rightMax[i + 1], height[i]);

    int water = 0;
    for (int i = 0; i < n; i++)
        water += min(leftMax[i], rightMax[i]) - height[i];

    cout << water;
    return 0;
}
