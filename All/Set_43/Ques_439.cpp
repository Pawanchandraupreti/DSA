// Missing Number Range

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    sort(arr.begin(), arr.end());
    
    vector<string> res;
    
    if (arr[0] != 0) {
        if (arr[0] == 1) res.push_back("0");
        else res.push_back("0->" + to_string(arr[0] - 1));
    }
    
    for (int i = 1; i < n; i++) {
        if (arr[i] - arr[i-1] > 1) {
            if (arr[i-1] + 1 == arr[i] - 1) {
                res.push_back(to_string(arr[i-1] + 1));
            } else {
                res.push_back(to_string(arr[i-1] + 1) + "->" + to_string(arr[i] - 1));
            }
        }
    }
    
    for (string s : res) cout << s << " ";
    return 0;
}

