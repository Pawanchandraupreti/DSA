// KMP String Matching
// Time Complexity: O(n + m)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> buildLPS(const string& pat) {
    int m = pat.size();
    vector<int> lps(m, 0);

    for(int i = 1, len = 0; i < m;) {
        if(pat[i] == pat[len]) {
            lps[i++] = ++len;
        } else if(len > 0) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }

    return lps;
}

vector<int> kmpSearch(const string& text, const string& pat) {
    int n = text.size(), m = pat.size();
    vector<int> ans;
    if(m == 0 || m > n) return ans;

    vector<int> lps = buildLPS(pat);

    for(int i = 0, j = 0; i < n;) {
        if(text[i] == pat[j]) {
            i++;
            j++;
        }

        if(j == m) {
            ans.push_back(i - j);
            j = lps[j - 1];
        } else if(i < n && text[i] != pat[j]) {
            if(j > 0) j = lps[j - 1];
            else i++;
        }
    }

    return ans;
}

int main() {
    string text = "aabaacaadaabaaba";
    string pat = "aaba";

    vector<int> pos = kmpSearch(text, pat);
    for(int i : pos) cout << i << " ";
}


