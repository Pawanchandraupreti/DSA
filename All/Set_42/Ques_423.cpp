// Maximum XOR Pair Using a Binary Trie

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* child[2] = {nullptr, nullptr};
};

void insertNumber(TrieNode* root, int number) {
    TrieNode* current = root;
    for (int bit = 31; bit >= 0; --bit) {
        int value = (number >> bit) & 1;
        if (!current->child[value]) current->child[value] = new TrieNode();
        current = current->child[value];
    }
}

int bestXor(TrieNode* root, int number) {
    TrieNode* current = root;
    int result = 0;
    for (int bit = 31; bit >= 0; --bit) {
        int value = (number >> bit) & 1;
        int preferred = value ^ 1;
        if (current->child[preferred]) {
            result |= (1 << bit);
            current = current->child[preferred];
        } else {
            current = current->child[value];
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int& number : numbers) cin >> number;
    if (n < 2) {
        cout << 0;
        return 0;
    }

    TrieNode* root = new TrieNode();
    insertNumber(root, numbers[0]);
    int answer = 0;
    for (int i = 1; i < n; ++i) {
        answer = max(answer, bestXor(root, numbers[i]));
        insertNumber(root, numbers[i]);
    }
    cout << answer;
    return 0;
}
