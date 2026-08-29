// Median of Two Sorted Arrays

#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(const vector<int>& first, const vector<int>& second) {
    const vector<int>* smaller = &first;
    const vector<int>* larger = &second;
    if (smaller->size() > larger->size()) {
        swap(smaller, larger);
    }

    int left = 0;
    int right = (int)smaller->size();
    int totalLeft = ((int)smaller->size() + (int)larger->size() + 1) / 2;

    while (left <= right) {
        int smallerCut = left + (right - left) / 2;
        int largerCut = totalLeft - smallerCut;

        int smallerLeft = (smallerCut == 0) ? INT_MIN : (*smaller)[smallerCut - 1];
        int smallerRight = (smallerCut == (int)smaller->size()) ? INT_MAX : (*smaller)[smallerCut];
        int largerLeft = (largerCut == 0) ? INT_MIN : (*larger)[largerCut - 1];
        int largerRight = (largerCut == (int)larger->size()) ? INT_MAX : (*larger)[largerCut];

        if (smallerLeft <= largerRight && largerLeft <= smallerRight) {
            int leftValue = max(smallerLeft, largerLeft);
            if (((int)smaller->size() + (int)larger->size()) % 2 == 1) {
                return leftValue;
            }
            return (leftValue + min(smallerRight, largerRight)) / 2.0;
        }

        if (smallerLeft > largerRight) {
            right = smallerCut - 1;
        } else {
            left = smallerCut + 1;
        }
    }

    return 0.0;
}

int main() {
    int firstSize, secondSize;
    cin >> firstSize >> secondSize;

    vector<int> first(firstSize), second(secondSize);
    for (int& value : first) cin >> value;
    for (int& value : second) cin >> value;

    cout << fixed << setprecision(1) << findMedianSortedArrays(first, second);
    return 0;
}