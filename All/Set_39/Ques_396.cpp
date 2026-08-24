// Word Search II

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    string word;
};

void searchBoard(vector<vector<char>>& board, int row, int column, TrieNode* node, vector<string>& result) {
    if (row < 0 || row >= (int)board.size() || column < 0 || column >= (int)board[0].size()) {
        return;
    }

    char letter = board[row][column];
    if (letter == '#' || !node->children.count(letter)) {
        return;
    }

    TrieNode* nextNode = node->children[letter];
    if (!nextNode->word.empty()) {
        result.push_back(nextNode->word);
        nextNode->word.clear();
    }

    board[row][column] = '#';
    searchBoard(board, row + 1, column, nextNode, result);
    searchBoard(board, row - 1, column, nextNode, result);
    searchBoard(board, row, column + 1, nextNode, result);
    searchBoard(board, row, column - 1, nextNode, result);
    board[row][column] = letter;
}

vector<string> findWords(vector<vector<char>>& board, const vector<string>& words) {
    TrieNode root;
    for (const string& word : words) {
        TrieNode* node = &root;
        for (char letter : word) {
            if (!node->children.count(letter)) {
                node->children[letter] = new TrieNode();
            }
            node = node->children[letter];
        }
        node->word = word;
    }

    vector<string> result;
    for (int row = 0; row < (int)board.size(); ++row) {
        for (int column = 0; column < (int)board[0].size(); ++column) {
            searchBoard(board, row, column, &root, result);
        }
    }
    sort(result.begin(), result.end());
    return result;
}

int main() {
    int rows, columns, wordCount;
    cin >> rows >> columns >> wordCount;

    vector<vector<char>> board(rows, vector<char>(columns));
    for (auto& row : board) {
        for (char& letter : row) cin >> letter;
    }

    vector<string> words(wordCount);
    for (string& word : words) cin >> word;

    for (const string& word : findWords(board, words)) {
        cout << word << ' ';
    }
    return 0;
}
