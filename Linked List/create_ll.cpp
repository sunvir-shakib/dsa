#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;

    Node(int val){
        this -> val = val;
        next = NULL;
    }

    ~Node(){
        //cout<<"~Node Destructor "<<val<<endl;
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
}; 

class List{
public: 
    Node *head;
    Node *tail;

    List(){
        head = NULL;
        tail = NULL;
    }

    ~List(){
        //cout<<"~List Desturctor"<<endl;
        if(head != NULL){
            delete head;
            head = NULL;
        }
    }

    void push_front(int val){
        Node *newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }
        else{
            newNode -> next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node *newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void insertATmiddle(int val, int pos){
    Node *newNode = new Node(val);
    Node *tmp = head;
    for(int i=0; i<pos-1; i++){
        if(tmp ==NULL){
            cout<<"Invalid"<<endl;
            return;
        }
        tmp = tmp -> next;       
        }
        newNode -> next = tmp -> next;
        tmp -> next = newNode;
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

    void print_ll(){
       Node *tmp = head;
     while(tmp != NULL){
        cout<< tmp ->val << " -> ";
        tmp = tmp -> next;
    }
    cout << "NULL" << endl;
    }
};

int main() 
{
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    cout<<"Push Front: ";
    ll.print_ll();
   
    // ll.push_back(4);
    // ll.push_back(5);
    // cout<<"Push Back: ";
    // ll.print_ll();

    // ll.insertATmiddle(99, 2);
    // cout<<"Insert at pos 2: ";
    // ll.print_ll();
    // return 0;

    ll.pop_front();
    cout<<"Pop Front: ";
    ll.print_ll();
}
