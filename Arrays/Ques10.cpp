// Sum of Digits

#include <iostream>
using namespace std;

int main() {
    int n = 245, sum = 0;

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    cout << sum;
    return 0;
}
