// Check if array is monotonic (non-increasing or non-decreasing)

#include <iostream>
#include <vector>
using namespace std;

bool isMonotonic(const vector<int>& a) {
    bool inc = true, dec = true;
    for (int i = 1; i < (int)a.size(); ++i) {
        if (a[i] < a[i-1]) inc = false;
        if (a[i] > a[i-1]) dec = false;
    }
    return inc || dec;
}

int main() {
    vector<int> a = {1, 2, 2, 3};
    cout << (isMonotonic(a) ? "Monotonic: Yes" : "Monotonic: No") << endl;
    return 0;
}
