// Intersection of Two Arrays II

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> frequency;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        frequency[value]++;
    }
    vector<int> answer;
    for (int i = 0; i < m; i++) {
        int value;
        cin >> value;
        if (frequency[value] > 0) {
            answer.push_back(value);
            frequency[value]--;
        }
    }
    for (int value : answer) cout << value << ' ';
    cout << '\n';
    return 0;
}
