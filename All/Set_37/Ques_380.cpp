// Implement a queue using two stacks

#include <bits/stdc++.h>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> incoming;
    stack<int> outgoing;

    void moveElements() {
        if (outgoing.empty()) {
            while (!incoming.empty()) {
                outgoing.push(incoming.top());
                incoming.pop();
            }
        }
    }

public:
    void push(int value) {
        incoming.push(value);
    }

    int pop() {
        moveElements();
        int value = outgoing.top();
        outgoing.pop();
        return value;
    }
};

int main() {
    int n;
    cin >> n;

    QueueUsingStacks queue;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        queue.push(value);
    }

    while (n > 0) {
        cout << queue.pop() << ' ';
        --n;
    }

    return 0;
}