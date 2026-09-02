// First Missing Positive

#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int>& numbers) {
    int size = (int)numbers.size();

    for (int index = 0; index < size; ++index) {
        while (numbers[index] > 0 && numbers[index] <= size && numbers[numbers[index] - 1] != numbers[index]) {
            swap(numbers[index], numbers[numbers[index] - 1]);
        }
    }

    for (int index = 0; index < size; ++index) {
        if (numbers[index] != index + 1) return index + 1;
    }

    return size + 1;
}

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int& number : numbers) cin >> number;

    cout << firstMissingPositive(numbers);
    return 0;
}


