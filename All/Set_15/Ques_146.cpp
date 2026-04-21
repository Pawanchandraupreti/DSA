// Find Kth Largest Element in Array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end(), greater<int>());
    return nums[k - 1];
}

int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    int k = 2;
    
    int result = findKthLargest(arr, k);
    
    cout << "Array: ";
    for(int num : arr) cout << num << " ";
    cout << endl;
    cout << "K: " << k << endl;
    cout << "Kth Largest Element: " << result << endl;
    
    return 0;
}
