// First Missing Positive

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {3, 4, -1, 1};
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i])
            swap(nums[i], nums[nums[i]-1]);
    }
    int missing = n + 1;
    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) { missing = i + 1; break; }
    }
    cout << "First missing positive: " << missing << endl;
    return 0;
}
