// Paint Fence Ways

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, colors;
    cin >> n >> colors;
    if (n == 1) {
        cout << colors << '\n';
        return 0;
    }
    long long same = colors, different = 1LL * colors * (colors - 1);
    for (int i = 3; i <= n; i++) {
        long long nextSame = different;
        long long nextDifferent = (same + different) * (colors - 1);
        same = nextSame;
        different = nextDifferent;
    }
    cout << same + different << '\n';
    return 0;
}
