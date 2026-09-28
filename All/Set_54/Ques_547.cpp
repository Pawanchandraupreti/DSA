// Reverse Linked List

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* next;
};

int main() {
    Node* head = new Node{1, new Node{2, new Node{3, nullptr}}};
    Node* prev = nullptr, *curr = head;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    Node* reversedHead = prev;
    while (prev) {
        cout << prev->value << ' ';
        prev = prev->next;
    }
    cout << '\n';
    while (reversedHead) {
        Node* next = reversedHead->next;
        delete reversedHead;
        reversedHead = next;
    }
    return 0;
}
