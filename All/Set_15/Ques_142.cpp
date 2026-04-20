// Next Permutation

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3};
    
    cout << "Original: ";
    for(int x : nums) cout << x << " ";
    cout << endl;
    
    do {
        for(int x : nums) cout << x << " ";
        cout << endl;
    } while(next_permutation(nums.begin(), nums.end()));
    
    return 0;
}
