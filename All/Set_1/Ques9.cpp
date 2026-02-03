// Fibonacci Series (first n terms)

#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int a = 0, b = 1;

    for (int i = 1; i <= n; i++) {
        cout << a << " ";
        int c = a + b;
        a = b;
        b = c;
    }

    return 0;
}
