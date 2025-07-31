#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val){
        this -> val = val;
        next = prev = NULL;
    }
};

class DoublyList{
public:
    Node *head;
    Node *tail;

    DoublyList(){
        head = NULL;
        tail = NULL;
    }

    void push_front(int val){
        Node *newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }

    }

    void printLL(){
        Node *tmp = head;
        while(tmp != NULL){
            cout<< tmp -> val<< " <=> ";
            tmp = tmp -> next;
        }
        cout<<"NULL"<<endl;

    }

} ;

int main() 
{
   DoublyList dbll;
   dbll. push_front(3);
   dbll.push_front(2);
   dbll.push_front(1);

   dbll.printLL();
   
    return 0;
}
