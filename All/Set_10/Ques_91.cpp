// Largest Rectangle in Histogram (Monotonic Stack)

#include <iostream>
#include <stack>
using namespace std;

int main() {

    int heights[] = {2,1,5,6,2,3};
    int n = 6;

    stack<int> st;
    int maxArea = 0;

    for(int i=0;i<=n;i++) {

        int h = (i==n)?0:heights[i];

        while(!st.empty() && h < heights[st.top()]) {

            int height = heights[st.top()];
            st.pop();

            int width;

            if(st.empty())
                width = i;
            else
                width = i - st.top() - 1;

            maxArea = max(maxArea, height * width);
        }

        st.push(i);
    }

    cout << maxArea;
}