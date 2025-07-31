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

Node *getInOrderSuccessor(Node *root){
    while(root -> left != NULL){
        root = root -> left;
    }
    return root; //IS
}

//delete Node
Node *delNode(Node *root, int val){
    if(root == NULL){
        return NULL;
    }

    if(val < root -> node){ //left subtree
        root -> left = delNode(root -> left, val);
    }

    else if(val > root -> node){ //right subtree
        root -> right = delNode(root -> right, val); 
    }

    else{
        //root == val
        //c1: 0 child
        if(root -> left && root -> right == NULL){
            delete root;
            return NULL;
        }

        //c2: 1 child
        if(root -> left == NULL || root -> right == NULL){
            return root -> left == NULL ? root -> right : root -> left;
        }

        //case3: 2 child
        Node *IS = getInOrderSuccessor(root -> right);
        root -> node = IS -> node;
        root -> right = delNode(root -> right, IS -> node); //c1 . c2
        return root;
    }   
    return root;
}

int main() 
{
   int ar[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
   Node *root = buildBST(ar, 9);
   inorder(root);
   cout<<endl;

   delNode(root , 5);

   inorder(root);
   cout<<endl;
    return 0;
}
