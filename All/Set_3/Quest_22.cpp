// Range Sum Query (Using Prefix Sum)

#include <iostream>
using namespace std;

int main() {
    int prefix[] = {2, 6, 12, 20}; // prefix sum
    int l = 1, r = 3;

    int sum;
    if (l == 0)
        sum = prefix[r];
    else
        sum = prefix[r] - prefix[l - 1];

    cout << sum;
    return 0;
}
