// Find the next greater element for every element in an array

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(const vector<int>& arr) {
    vector<int> answer(arr.size(), -1);
    stack<int> indices;

    for (int i = 0; i < (int)arr.size(); ++i) {
        while (!indices.empty() && arr[indices.top()] < arr[i]) {
            answer[indices.top()] = arr[i];
            indices.pop();
        }
        indices.push(i);
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> answer = nextGreaterElements(arr);
    for (int value : answer) {
        cout << value << ' ';
    }

    return 0;
}
