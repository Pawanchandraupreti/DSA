// Generate All Subsets (Power Set)

#include <iostream>
#include <vector>
using namespace std;

void generate(vector<int>& nums, vector<int>& curr, int index) {
    if (index == nums.size()) {
        for (int x : curr) cout << x << " ";
        cout << endl;
        return;
    }
    curr.push_back(nums[index]);
    generate(nums, curr, index + 1);
    curr.pop_back();
    generate(nums, curr, index + 1);
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> curr;

    generate(nums, curr, 0);
    return 0;
}