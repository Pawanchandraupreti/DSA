// Asteroid Collision

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> st;

    while (n--) {
        int x;
        cin >> x;
        bool alive = true;
        while (alive && x < 0 && !st.empty() && st.back() > 0) {
            if (st.back() < -x) st.pop_back();
            else if (st.back() == -x) {
                st.pop_back();
                alive = false;
            } else alive = false;
        }
        if (alive) st.push_back(x);
    }

    for (int x : st) cout << x << ' ';
    return 0;
}
