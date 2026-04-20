// Set Matrix Zeroes

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    
    set<int> rows, cols;
    int m = matrix.size();
    int n = matrix[0].size();
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 0) {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(rows.count(i) || cols.count(j)) {
                matrix[i][j] = 0;
            }
        }
    }
    
    cout << "Matrix after zeroing:" << endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
