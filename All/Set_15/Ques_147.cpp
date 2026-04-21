// Merge Two Sorted Arrays

#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    vector<int> result;
    int i = 0, j = 0;
    
    while(i < arr1.size() && j < arr2.size()) {
        if(arr1[i] <= arr2[j]) {
            result.push_back(arr1[i++]);
        } else {
            result.push_back(arr2[j++]);
        }
    }
    
    while(i < arr1.size()) {
        result.push_back(arr1[i++]);
    }
    
    while(j < arr2.size()) {
        result.push_back(arr2[j++]);
    }
    
    return result;
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};
    
    vector<int> merged = mergeSortedArrays(arr1, arr2);
    
    cout << "Array 1: ";
    for(int num : arr1) cout << num << " ";
    cout << endl;
    cout << "Array 2: ";
    for(int num : arr2) cout << num << " ";
    cout << endl;
    cout << "Merged Array: ";
    for(int num : merged) cout << num << " ";
    cout << endl;
    
    return 0;
}
