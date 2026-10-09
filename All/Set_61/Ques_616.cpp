// Generate Permutations

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int &value : numbers) cin >> value;
    sort(numbers.begin(), numbers.end());
    do {
        for (int value : numbers) cout << value << ' ';
        cout << '\n';
    } while (next_permutation(numbers.begin(), numbers.end()));
    return 0;
}


