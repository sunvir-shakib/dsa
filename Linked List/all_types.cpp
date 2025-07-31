#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int val) { 
        data = val;
        next = NULL;
    }

    ~Node() {
        // cout << "~Node " << data << endl;
        if (next != NULL) {
            delete next;
            next = NULL;
        }
    }
};

class List {
    Node *head;
    Node *tail;

public:
    List() {
        head = NULL;
        tail = NULL;
    }

    ~List() {
        // cout << "~List " << endl;
        if (head != NULL) {
            delete head;
            head = NULL;
        }
    }

    void push_front(int val) {
        Node *newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node *newNode = new Node(val);
        if (head == NULL) {
            head = tail = NULL;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insert(int val, int pos) {
        Node *newNode = new Node(val);
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++) {
            if (temp == NULL) {
                cout << "Position is invalid\n";
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front() {
        if (head == NULL) {
            cout << "LL is empty\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back() {
        Node *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    int searchITR(int key) {
        Node *temp = head;
        int idx = 0;
        while (temp != NULL) {
            if (temp->data == key) {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    int helper(Node *temp, int key) {
        if (temp == NULL) {
            return -1;
        }
        if (temp->data == key) 
        return 0;

        int idx = helper(temp->next, key);
        if (idx == -1) {
            return -1;
        }
        return idx + 1;
    }

    int searchREC(int key) {
        return helper(head, key);
    }

    void reverse() {
        Node *curr = head;
        Node *prev = NULL;
        tail = head;
        while (curr != NULL) {
            Node *next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        head = prev;
    }

    int getSize() {
        int sz = 0;
        Node *temp = head;
        while (temp != NULL) {
            temp = temp->next;
            sz++;
        }
        return sz;
    }

    void removeNTH(int n) { //size-n+1
        int size = getSize();
        Node *prev = head;
        for (int i = 1; i < (size - n); i++) {
            prev = prev->next;
        }

        Node *todel = prev->next;
        cout << "Going to del: " << todel->data << endl;
        prev->next = prev->next->next;
    }

    void printList() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n" << endl;
    }
};

int main() {
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printList();
    // 1 -> 2 -> 3 -> NULL

    ll.removeNTH(2);
    ll.printList();

    return 0;
}
