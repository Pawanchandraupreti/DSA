// Container With Most Water (Two Pointers)

#include <iostream>
using namespace std;

int main() {
    int height[] = {1,8,6,2,5,4,8,3,7};
    int n = 9;

    int l = 0, r = n - 1;
    int maxArea = 0;

    while (l < r) {
        int area = min(height[l], height[r]) * (r - l);
        maxArea = max(maxArea, area);

        if (height[l] < height[r])
            l++;
        else
            r--;
    }

    cout << maxArea;
    return 0;
}


