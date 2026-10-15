// Three Sum to Zero

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());

    for (int i = 0; i < n - 2; i++) {
        if (i && a[i] == a[i - 1]) continue;
        int left = i + 1, right = n - 1;
        while (left < right) {
            long long sum = 1LL * a[i] + a[left] + a[right];
            if (sum == 0) {
                cout << a[i] << ' ' << a[left] << ' ' << a[right] << '\n';
                int first = a[left], last = a[right];
                while (left < right && a[left] == first) left++;
                while (left < right && a[right] == last) right--;
            } else if (sum < 0) left++;
            else right--;
        }
    }
    return 0;
}
