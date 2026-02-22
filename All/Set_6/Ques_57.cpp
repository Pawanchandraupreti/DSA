// Next Smaller Element (Monotonic Stack)

#include <iostream>
#include <stack>
using namespace std;

int main() {
    int arr[] = {4,8,5,2,25};
    int n = 5;

    stack<int> st;
    int result[5];

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() >= arr[i])
            st.pop();

        result[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }

    for (int i = 0; i < n; i++)
        cout << result[i] << " ";

    return 0;
}

