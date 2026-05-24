// Stable Partition: preserve order - positives then negatives

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {-1, 3, -2, 4, -5, 6};
    vector<int> pos, neg;
    for (int x : arr) {
        if (x >= 0) pos.push_back(x); else neg.push_back(x);
    }
    cout << "Array after stable partition: ";
    for (int x : pos) cout << x << " ";
    for (int x : neg) cout << x << " ";
    cout << endl;
    return 0;
}
