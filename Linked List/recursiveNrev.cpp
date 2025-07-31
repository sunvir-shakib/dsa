#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
}; 

void recursiveLL(Node *n) {
    if (n == NULL) {
        return;
    }
    cout << n->val << " -> ";
    recursiveLL(n->next);
}

void revLL(Node *n) {
    if (n == NULL)
        return;

    revLL(n->next);
    cout << n->val << " -> ";
}

// Sort linked list using bubble sort 
void sortLL(Node *head) {
    for (Node *i = head; i != NULL; i = i->next) {
        for (Node *j = i->next; j != NULL; j = j->next) {
            if (i->val > j->val) {
                swap(i->val, j->val);
            }
        }
    }
}

int main() {

    Node *head = new Node(40);
    Node *a = new Node(10);
    Node *b = new Node(30);
    Node *c = new Node(5);
    Node *d = new Node(20);

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;

    cout << "Original List:\n";
    recursiveLL(head);
    cout << "NULL\n";

    cout << "Reversed List:\n";
    revLL(head);
    cout << "NULL\n";

    sortLL(head);

    cout << "Sorted List:\n";
    recursiveLL(head);
    cout << "NULL\n";

    return 0;
}
