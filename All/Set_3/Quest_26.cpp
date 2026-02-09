// Count Frequency Using Hashing

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[] = {1, 2, 2, 3, 1, 4};
    int n = 6;

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    for (auto it : mp)
        cout << it.first << " -> " << it.second << endl;

    return 0;
}
