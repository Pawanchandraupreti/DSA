// Majority Element (Boyer-Moore Voting Algorithm)

#include <iostream>
#include <vector>
using namespace std;

int majorityElement(const vector<int>& nums) {
    int count = 0, candidate = 0;
    for (int n : nums) {
        if (count == 0) candidate = n;
        count += (n == candidate) ? 1 : -1;
    }
    return candidate;
}

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << "Majority element: " << majorityElement(nums) << endl;
    return 0;
}
