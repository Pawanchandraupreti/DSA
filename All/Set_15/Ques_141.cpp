// LCM and GCD of Two Numbers

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int a = 12, b = 18;
    
    int g = gcd(a, b);
    int l = lcm(a, b);
    
    cout << "GCD: " << g << endl;
    cout << "LCM: " << l << endl;
    cout << "Product: " << (g * l) << endl;
    
    return 0;
}
