// Queue Reconstruction by Height

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> people(n);
    for (auto &[height, ahead] : people) cin >> height >> ahead;
    sort(people.begin(), people.end(), [](auto a, auto b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });
    vector<pair<int, int>> answer;
    for (auto person : people) answer.insert(answer.begin() + person.second, person);
    for (auto [height, ahead] : answer) cout << height << ' ' << ahead << '\n';
    return 0;
}
