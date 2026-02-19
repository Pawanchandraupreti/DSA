// Jump Game (Greedy)

#include <iostream>
using namespace std;

int main() {
    int nums[] = {2,3,1,1,4};
    int n = 5;

    int maxReach = 0;

    for (int i = 0; i < n; i++) {
        if (i > maxReach) {
            cout << "No";
            return 0;
        }
        maxReach = max(maxReach, i + nums[i]);
    }

    cout << "Yes";
    return 0;
}
