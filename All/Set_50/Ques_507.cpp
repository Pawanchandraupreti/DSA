// Permutations Count

#include <bits/stdc++.h>
using namespace std;

void generate(vector<int> &a, int index) {
    if (index == (int)a.size()) {
        for (int x : a) cout << x << ' ';
        cout << '\n';
        return;
    }

    for (int i = index; i < (int)a.size(); i++) {
        swap(a[index], a[i]);
        generate(a, index + 1);
        swap(a[index], a[i]);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    generate(a, 0);
    return 0;
}
