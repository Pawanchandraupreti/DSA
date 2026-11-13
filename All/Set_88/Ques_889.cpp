// Linear Recurrence with Matrix Exponentiation

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

vector<vector<long long>> multiply(const vector<vector<long long>> &a,
                                   const vector<vector<long long>> &b) {
    int size = a.size();
    vector<vector<long long>> result(size, vector<long long>(size));
    for (int i = 0; i < size; i++) for (int k = 0; k < size; k++)
        for (int j = 0; j < size; j++)
            result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
    return result;
}

int main() {
    int order;
    long long index;
    cin >> order >> index;
    vector<long long> initial(order), coefficient(order);
    for (long long &x : initial) cin >> x;
    for (long long &x : coefficient) cin >> x;
    if (index < order) {
        cout << initial[index] % MOD << '\n';
        return 0;
    }
    vector<vector<long long>> matrix(order, vector<long long>(order));
    for (int i = 0; i < order; i++) matrix[0][i] = coefficient[i] % MOD;
    for (int i = 1; i < order; i++) matrix[i][i - 1] = 1;
    vector<vector<long long>> result(order, vector<long long>(order));
    for (int i = 0; i < order; i++) result[i][i] = 1;
    long long exponent = index - order + 1;
    while (exponent) {
        if (exponent & 1) result = multiply(result, matrix);
        matrix = multiply(matrix, matrix);
        exponent >>= 1;
    }
    long long answer = 0;
    for (int i = 0; i < order; i++) answer = (answer + result[0][i] * initial[order - 1 - i]) % MOD;
    cout << answer << '\n';
    return 0;
}
