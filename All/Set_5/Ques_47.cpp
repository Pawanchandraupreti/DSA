// Next Greater Element (Using Stack)

#include <iostream>
#include <stack>
using namespace std;

int main() {
    int arr[] = {4, 5, 2, 10};
    int n = 4;

    stack<int> st;
    int result[4];

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i])
            st.pop();

        result[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }

    for (int i = 0; i < n; i++)
        cout << result[i] << " ";

    return 0;
}

