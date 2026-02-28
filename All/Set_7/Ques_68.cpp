// House Robber

#include <iostream>
using namespace std;

int main() {
    int nums[] = {2,7,9,3,1};
    int n = 5;

    if (n == 1) {
        cout << nums[0];
        return 0;
    }

    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++) {
        int curr = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = curr;
    }

    cout << prev1;
    return 0;
}