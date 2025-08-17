#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

struct Node{
    unordered_map<char, Node*> children;
    bool end;

    Node(){
        end = false;
    }
};

class Trie{
    Node* root;

public:
    Trie(){
        root = new Node();
    }

    void insert (string key){ //O(L)
        Node *tmp = root;
        for(int i=0; i<key.size(); i++){
            if (tmp->children.count(key[i]) == 0) { 
                tmp -> children[key[i]] = new Node(); //insert
            }
            tmp = tmp -> children[key[i]];
        }
        tmp -> end = true;
    }

    bool search(string key){ //O(L)
        Node *tmp = root;
        for(int i=0; i<key.size(); i++){
           if(tmp -> children.count(key[i])){
            tmp = tmp -> children[key[i]];
           } 
           else{
            return false;
           }
        }
        return tmp -> end;
    }

};

int main() 
{
   vector<string> words = {"the", "a", "there", "their", "any", "thee"};
    Trie trie;

    for(int i=0; i<words.size(); i++){
        trie.insert(words[i]);
    }

    cout<<trie.search("their")<< endl;
    cout << trie.search("hero") << endl;
   
    return 0;
}
