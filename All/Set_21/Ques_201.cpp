// Check if one array is rotation of another

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isRotation(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) return false;
    string sa, sb;
    for (int x : a) sa += to_string(x) + ",";
    for (int x : b) sb += to_string(x) + ",";
    return (sa + sa).find(sb) != string::npos;
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {3, 4, 5, 1, 2};

    cout << (isRotation(a, b) ? "Rotation: Yes" : "Rotation: No") << endl;
    return 0;
}
