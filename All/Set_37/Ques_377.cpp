// Find the product of all array elements except the current element

#include <bits/stdc++.h>
using namespace std;

vector<long long> productExceptSelf(const vector<int>& arr) {
    vector<long long> answer(arr.size(), 1);
    long long prefix = 1;

    for (int i = 0; i < (int)arr.size(); ++i) {
        answer[i] = prefix;
        prefix *= arr[i];
    }

    long long suffix = 1;
    for (int i = (int)arr.size() - 1; i >= 0; --i) {
        answer[i] *= suffix;
        suffix *= arr[i];
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int& value : arr) {
        cin >> value;
    }

    vector<long long> answer = productExceptSelf(arr);
    for (long long value : answer) {
        cout << value << ' ';
    }

    return 0;
}


