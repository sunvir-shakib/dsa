#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;

    Node(int val){
        this -> val = val;
        this ->next = NULL;
    }
};

class List{
public:
    Node *head;
    Node *tail;
    List( ){
        head = NULL;
        tail = NULL;
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
   ll.
   
    return 0;
}
