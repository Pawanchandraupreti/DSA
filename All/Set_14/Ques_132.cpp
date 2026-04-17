// Rabin-Karp String Matching
// Time Complexity: Average O(n + m), worst-case O(n * m)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> rabinKarp(string text, string pat) {
    const int base = 256;
    const int mod = 1000000007;

    int n = text.size(), m = pat.size();
    vector<int> ans;
    if(m > n) return ans;

    long long pHash = 0, tHash = 0, power = 1;

    for(int i = 0; i < m - 1; i++)
        power = (power * base) % mod;

    for(int i = 0; i < m; i++) {
        pHash = (pHash * base + pat[i]) % mod;
        tHash = (tHash * base + text[i]) % mod;
    }

    for(int i = 0; i <= n - m; i++) {
        if(pHash == tHash) {
            bool ok = true;
            for(int j = 0; j < m; j++) {
                if(text[i + j] != pat[j]) {
                    ok = false;
                    break;
                }
            }
            if(ok) ans.push_back(i);
        }

        if(i < n - m) {
            tHash = (tHash - text[i] * power) % mod;
            if(tHash < 0) tHash += mod;
            tHash = (tHash * base + text[i + m]) % mod;
        }
    }

    return ans;
}

int main() {
    string text = "ababcabcabababd";
    string pat = "ababd";

    vector<int> pos = rabinKarp(text, pat);
    for(int i : pos) cout << i << " ";
}




