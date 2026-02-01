// Count Digits in a Number

#include <iostream>
using namespace std;

int main() {
    int n = 4567, count = 0;

    while (n > 0) {
        count++;
        n /= 10;
    }

    cout << count;
    return 0;
}
