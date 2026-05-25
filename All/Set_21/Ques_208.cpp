// Merge two sorted arrays into a new sorted array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> a = {1,3,5};
    vector<int> b = {2,4,6,7};
    vector<int> merged;
    merged.reserve(a.size()+b.size());
    merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(merged));
    cout << "Merged array: ";
    for (int x : merged) cout << x << " ";
    cout << endl;
    return 0;
}
