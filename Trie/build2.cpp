#include<iostream>
#include<string>
using namespace std;

struct Node{
    Node *links[26];
    bool flag;

    Node(){
        flag = false;
    }
};


class Trie{
public:
    Node *root;

    Trie(){
        root = new Node();
    }

    void insert(string words){
        Node *tmp = root; 
        for(int i=0; i<words.size(); i++){
            
        }
    }


};


int main() 
{
   
   
    return 0;
}
