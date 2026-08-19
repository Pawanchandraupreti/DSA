// Merge two sorted arrays without using an extra array for the result

#include <bits/stdc++.h>
using namespace std;

vector<int> mergeSortedArrays(const vector<int>& first, const vector<int>& second) {
    vector<int> merged;
    int i = 0;
    int j = 0;

    while (i < (int)first.size() && j < (int)second.size()) {
        if (first[i] <= second[j]) {
            merged.push_back(first[i]);
            ++i;
        } else {
            merged.push_back(second[j]);
            ++j;
        }
    }

    while (i < (int)first.size()) {
        merged.push_back(first[i]);
        ++i;
    }

    while (j < (int)second.size()) {
        merged.push_back(second[j]);
        ++j;
    }

    return merged;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> first(n), second(m);
    for (int& value : first) cin >> value;
    for (int& value : second) cin >> value;

    vector<int> merged = mergeSortedArrays(first, second);
    for (int value : merged) {
        cout << value << ' ';
    }

    return 0;
}
