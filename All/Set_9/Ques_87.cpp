// Monotonic Stack – Next Greater Element

#include <iostream>
#include <stack>
using namespace std;

int main() {

    int arr[] = {4,5,2,10,8};
    int n = 5;

    stack<int> st;

    for(int i=n-1;i>=0;i--) {

        while(!st.empty() && st.top()<=arr[i])
            st.pop();

        if(st.empty())
            cout<<-1<<" ";
        else
            cout<<st.top()<<" ";

        st.push(arr[i]);
    }
}