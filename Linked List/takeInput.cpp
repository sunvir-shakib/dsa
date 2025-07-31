#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

void printLL(Node *head){
    Node *tmp = head;
    while(tmp != NULL){
        cout << tmp->val << " -> ";
        tmp = tmp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    
    int n;
    cout << "How many elements? ";
    cin >> n;
    
    if(n <= 0) {
        cout << "List is empty." << endl;
        return 0;
    }
    
    Node *head = NULL;
    Node *tail = NULL;
    

    for(int i = 0; i < n; i++) {
        int value;
        cout << "Enter element " << (i + 1) << ": ";
        cin >> value;
        
        Node *newNode = new Node(value);
        
        if(head == NULL) {
            head = tail = newNode;
        }

        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
  
    cout << "\nCreated Linked List: ";
    printLL(head);
    
    return 0;
}