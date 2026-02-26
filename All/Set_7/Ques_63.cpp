// Combination Sum (Basic Version)

#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int>& arr, int target, vector<int>& curr, int index) {
    if (target == 0) {
        for (int x : curr) cout << x << " ";
        cout << endl;
        return;
    }
    if (index == arr.size() || target < 0)
        return;
    curr.push_back(arr[index]);
    solve(arr, target - arr[index], curr, index);
    curr.pop_back();
    solve(arr, target, curr, index + 1);
}

int main() {
    vector<int> arr = {2,3,6,7};
    vector<int> curr;
    solve(arr, 7, curr, 0);
    return 0;
}

