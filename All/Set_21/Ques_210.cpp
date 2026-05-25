// Count set bits for each number in an array

#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main() {
    vector<int> nums = {3, 5, 7};
    cout << "Set bits counts: ";
    for (int x : nums) cout << __builtin_popcount(x) << " ";
    cout << endl;
    return 0;
}
