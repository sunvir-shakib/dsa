#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int node;
    Node *left;
    Node *right;

    Node(int node){
        this -> node = node;
        left = right = NULL;
    }
};

Node *insert(Node *root, int idx){
    if(root == NULL){
        root = new Node(idx);
        return root;
    }

    if(idx < root->node ){ //left subtree
        root -> left =insert(root -> left, idx);
    }

    else{ //right subtree
        root -> right =insert(root -> right, idx);
    }
    return root;
}

Node *buildBST(int *ar, int n){
    Node *root = NULL;
    for(int i=0; i<n; i++){
       root = insert(root, ar[i]);
    }
    return root;
}

void inorder(Node* root) {
    if (root == nullptr) 
    return;

    inorder(root->left);  
    cout << root-> node << " ";
    inorder(root->right);    
}

int main() 
{
   int ar[6] = {5, 1, 3, 4, 2, 7};
   Node *root = buildBST(ar, 6);
   inorder(root);
    return 0;
}
