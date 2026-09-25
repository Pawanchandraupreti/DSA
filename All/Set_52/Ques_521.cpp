// 3Sum

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    cin >> target;
    sort(a.begin(), a.end());

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = a[i] + a[left] + a[right];
            if (sum == target) {
                cout << a[i] << ' ' << a[left] << ' ' << a[right] << '\n';
                return 0;
            }
            if (sum < target) left++;
            else right--;
        }
    }

    cout << "No triplet\n";
    return 0;
}
