// Merge K Sorted Lists

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int value) : val(value), next(nullptr) {}
};

struct Compare {
    bool operator()(const ListNode* first, const ListNode* second) const {
        return first->val > second->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> heap;
    for (ListNode* list : lists) {
        if (list) heap.push(list);
    }

    ListNode head(0);
    ListNode* current = &head;

    while (!heap.empty()) {
        ListNode* smallest = heap.top();
        heap.pop();
        current->next = smallest;
        current = current->next;

        if (smallest->next) heap.push(smallest->next);
    }

    return head.next;
}

int main() {
    int k;
    cin >> k;

    vector<ListNode*> lists(k);
    for (int index = 0; index < k; ++index) {
        int size;
        cin >> size;
        ListNode* head = nullptr;
        ListNode* current = nullptr;
        for (int element = 0; element < size; ++element) {
            int value;
            cin >> value;
            ListNode* node = new ListNode(value);
            if (!head) head = node;
            if (current) current->next = node;
            current = node;
        }
        lists[index] = head;
    }

    ListNode* merged = mergeKLists(lists);
    while (merged) {
        cout << merged->val << ' ';
        merged = merged->next;
    }
    return 0;
}
