// Longest Consecutive Sequence (Hashing)

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int arr[] = {100,4,200,1,3,2};
    int n = 6;

    unordered_set<int> st(arr, arr + n);
    int longest = 0;

    for (int num : st) {
        if (!st.count(num - 1)) {
            int current = num;
            int length = 1;

            while (st.count(current + 1)) {
                current++;
                length++;
            }

            longest = max(longest, length);
        }
    }

    cout << longest;
    return 0;
}

