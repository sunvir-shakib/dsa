#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

struct Node{
    unordered_map<char, Node*> children;
    bool end;
    int freq;

    Node(){
        end = false;
    }
};

class Trie{
    Node* root;

public:
    Trie(){
        root = new Node();
        root -> freq = -1;
    }

    void insert (string key){ //O(L)
        Node *tmp = root;
        for(int i=0; i<key.size(); i++){
            if (tmp->children.count(key[i]) == 0) { 
                tmp -> children[key[i]] = new Node(); //insert
                tmp -> children[key[i]] -> freq = 1;
            }
            else{
                tmp -> children[key[i]] -> freq++;
            }
            tmp = tmp -> children[key[i]];
        }
        tmp -> end = true;
    }

    string getPrefix(string key){ //O(L)
        Node *tmp = root;
        string prefix = " ";

        for(int i=0; i<key.size(); i++){
            prefix = prefix + key[i];

            if(tmp -> children[key[i]] -> freq == 1){
                break;
            }
            tmp = tmp -> children[key[i]];
        }
        return prefix;
    }

};

void prefixProb(vector<string> dict){ //O(n*L)
    Trie trie;
    for(int i=0; i<dict.size(); i++){
        trie.insert(dict[i]);
    }

    for(int i=0; i<dict.size(); i++){
        cout << trie.getPrefix(dict[i]) << endl;
    }

}

int main() 
{
   vector<string> dict = {"zebra", "dog", "duck", "dove"};
    prefixProb(dict);
    return 0;
}
