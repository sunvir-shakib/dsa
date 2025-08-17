#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

class Node{
public:
    unordered_map<char, Node*> children;
    bool endOfWord;

    Node(){
        endOfWord = false;
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
        tmp -> endOfWord = true;
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
        return tmp -> endOfWord;
    }
};

// 
bool helper(Trie &trie, string key){
    if(key.size() == 0){
        return true;
    }

    for(int i=0; i<key.size(); i++){
        string first = key.substr(0, i+1);
        string last = key.substr(i+1);

        if(trie.search(first) && helper(trie, last)){
            return true;
        }
    }
    return false;
}

// 
bool wordBreak(vector<string> &dict, string key){
    Trie trie;
    for(int i=0; i<dict.size(); i++){
        trie.insert(dict[i]);
    }
    return helper(trie, key);
}

int main() 
{
   vector<string> dict = {"i", "like", "samsung", "mobile", "ice"};

   cout << wordBreak(dict, "ilikesamsung") << endl; // should print 1 (true)
   cout << wordBreak(dict, "ilikemobile") << endl;  // should print 1 (true)
   cout << wordBreak(dict, "icecream") << endl;     // should print 0 (false)

   return 0;
}
