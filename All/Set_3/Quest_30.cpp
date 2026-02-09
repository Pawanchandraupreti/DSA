// Check If Pair with Given Sum Exists

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int arr[] = {8, 4, 1, 6};
    int n = 4, target = 10;

    unordered_set<int> st;

    for (int i = 0; i < n; i++) {
        if (st.count(target - arr[i])) {
            cout << "Yes";
            return 0;
        }
        st.insert(arr[i]);
    }

    cout << "No";
    return 0;
}
