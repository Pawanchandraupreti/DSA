// Sliding Window – Longest Substring Without Repeating Characters

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    string s = "abcabcbb";

    unordered_set<char> st;
    int left = 0, ans = 0;

    for(int right = 0; right < s.length(); right++) {

        while(st.count(s[right])) {
            st.erase(s[left]);
            left++;
        }

        st.insert(s[right]);
        ans = max(ans, right - left + 1);
    }

    cout << ans;
}
