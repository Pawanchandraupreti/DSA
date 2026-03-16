// Trapping Rain Water (Two Pointer)

#include <iostream>
using namespace std;

int main() {

    int height[] = {4,2,0,3,2,5};
    int n = 6;

    int left = 0, right = n-1;
    int leftMax = 0, rightMax = 0;
    int water = 0;

    while(left < right) {

        if(height[left] < height[right]) {

            if(height[left] >= leftMax)
                leftMax = height[left];
            else
                water += leftMax - height[left];

            left++;
        }

        else {

            if(height[right] >= rightMax)
                rightMax = height[right];
            else
                water += rightMax - height[right];

            right--;
        }
    }

    cout << water;
}
