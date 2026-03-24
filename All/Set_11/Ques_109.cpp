// Word Ladder (BFS + Set)

#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

int main() {

    string beginWord = "hit";
    string endWord = "cog";

    unordered_set<string> wordList = {
        "hot","dot","dog","lot","log","cog"
    };

    queue<pair<string,int>> q;
    q.push({beginWord,1});

    while(!q.empty()) {

        auto [word,level] = q.front();
        q.pop();

        if(word == endWord) {
            cout << level;
            return 0;
        }

        for(int i=0;i<word.length();i++) {
            string temp = word;

            for(char c='a'; c<='z'; c++) {
                temp[i] = c;

                if(wordList.count(temp)) {
                    q.push({temp, level+1});
                    wordList.erase(temp);
                }
            }
        }
    }

    cout << 0;
}
