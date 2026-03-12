// KMP String Matching

#include <iostream>
#include <vector>
using namespace std;

vector<int> computeLPS(string pat) {

    int m = pat.length();
    vector<int> lps(m);

    int len = 0;
    int i = 1;

    while(i < m) {

        if(pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {

            if(len != 0)
                len = lps[len-1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

int main() {

    string text="ababcabcabababd";
    string pat="ababd";

    vector<int> lps=computeLPS(pat);

    int i=0,j=0;

    while(i<text.length()) {

        if(text[i]==pat[j]) {
            i++; j++;
        }

        if(j==pat.length()) {
            cout<<"Found at "<<i-j;
            j=lps[j-1];
        }

        else if(i<text.length() && text[i]!=pat[j]) {

            if(j!=0)
                j=lps[j-1];
            else
                i++;
        }
    }
}