// Permutation Cycles

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> perm(n);
    
    for (int i = 0; i < n; i++) {
        cin >> perm[i];
        perm[i]--;
    }
    
    vector<bool> visited(n, false);
    vector<int> cycles;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int len = 0, curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = perm[curr];
                len++;
            }
            cycles.push_back(len);
        }
    }
    
    for (int c : cycles) cout << c << ' ';
    return 0;
}


