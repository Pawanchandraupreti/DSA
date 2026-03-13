// Trie (Prefix Tree)

#include <iostream>
using namespace std;

struct TrieNode {
    TrieNode* child[26];
    bool end;

    TrieNode() {
        for(int i=0;i<26;i++)
            child[i]=NULL;
        end=false;
    }
};

void insert(TrieNode* root,string word) {

    TrieNode* node=root;

    for(char c:word) {

        int idx=c-'a';

        if(node->child[idx]==NULL)
            node->child[idx]=new TrieNode();

        node=node->child[idx];
    }

    node->end=true;
}

bool search(TrieNode* root,string word) {

    TrieNode* node=root;

    for(char c:word) {

        int idx=c-'a';

        if(node->child[idx]==NULL)
            return false;

        node=node->child[idx];
    }

    return node->end;
}

int main() {

    TrieNode* root=new TrieNode();

    insert(root,"apple");

    cout<<search(root,"apple");
}

