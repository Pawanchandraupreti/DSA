// Kth largest element using nth_element

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2; // 2nd largest
    nth_element(nums.begin(), nums.end()-k, nums.end());
    int kth = nums[nums.size()-k];
    cout << "Kth largest (k=2): " << kth << endl;
    return 0;
}
