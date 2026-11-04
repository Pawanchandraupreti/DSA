// Simplify Unix Path

#include <bits/stdc++.h>
using namespace std;

int main() {
    string path, part;
    cin >> path;
    stringstream stream(path);
    vector<string> stack;
    while (getline(stream, part, '/')) {
        if (part.empty() || part == ".") continue;
        if (part == "..") {
            if (!stack.empty()) stack.pop_back();
        } else stack.push_back(part);
    }
    if (stack.empty()) cout << "/\n";
    else {
        for (string &value : stack) cout << '/' << value;
        cout << '\n';
    }
    return 0;
}
