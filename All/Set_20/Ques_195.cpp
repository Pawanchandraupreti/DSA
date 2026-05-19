// Count Occurrences of an Element

#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 2, 8, 2, 9, 2, 3, 2};
    int n = 8;
    int target = 2;
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    
    cout << "Element " << target << " occurs " << count << " times" << endl;
    
    return 0;
}
