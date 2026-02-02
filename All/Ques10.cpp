// Check Armstrong Number

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n = 153, temp = n, sum = 0;

    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit * digit;
        n /= 10;
    }

    if (sum == temp)
        cout << "Armstrong";
    else
        cout << "Not Armstrong";

    return 0;
}
