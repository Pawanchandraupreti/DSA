// First Repeating Element

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int arr[] = {10, 5, 3, 4, 3, 5, 6};
    int n = 7;

    unordered_set<int> st;
    int ans = -1;

    for (int i = n - 1; i >= 0; i--) {
        if (st.count(arr[i]))
            ans = arr[i];
        else
            st.insert(arr[i]);
    }

    cout << ans;
    return 0;
}
