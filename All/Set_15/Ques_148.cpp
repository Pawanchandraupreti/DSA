// Maximum Subarray Sum (Kadane's Algorithm)

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maxSubarraySum(vector<int>& nums) {
    int maxSoFar = nums[0];
    int maxEndingHere = nums[0];
    
    for(int i = 1; i < nums.size(); i++) {
        maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    
    return maxSoFar;
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    int result = maxSubarraySum(arr);
    
    cout << "Array: ";
    for(int num : arr) cout << num << " ";
    cout << endl;
    cout << "Maximum Subarray Sum: " << result << endl;
    
    return 0;
}

