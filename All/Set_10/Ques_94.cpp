// Word Search (Backtracking)

#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {

    if(k == word.length())
        return true;

    if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[k])
        return false;

    char temp = board[i][j];
    board[i][j] = '#';

    bool found =
        dfs(board,word,i+1,j,k+1) ||
        dfs(board,word,i-1,j,k+1) ||
        dfs(board,word,i,j+1,k+1) ||
        dfs(board,word,i,j-1,k+1);

    board[i][j] = temp;

    return found;
}

int main() {

    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";

    for(int i=0;i<board.size();i++) {
        for(int j=0;j<board[0].size();j++) {
            if(dfs(board,word,i,j,0)) {
                cout << "Found";
                return 0;
            }
        }
    }

    cout << "Not Found";
}


