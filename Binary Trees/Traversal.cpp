#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//tc - O(n)
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

int idx = -1;

Node* buildTree(vector<int>& nodes) {
    idx++;
    if (nodes[idx] == -1) {
        return NULL;
    }
    Node *currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);  // Left subtree
    currNode->right = buildTree(nodes); // Right subtree
    return currNode;
}

//pre order traversal
void preorder(Node *root){

    if(root == NULL){
        return;
    }

    cout<< root -> data<<" ";
    preorder(root -> left);
    preorder(root -> right);
}

//in order traaversal
void inOrder(Node *root){
    if(root == NULL){
        return;
    }

    inOrder(root -> left);
    cout << root-> data<< " ";
    inOrder(root -> right);
}

//post Order
void postOrder(Node *root){
    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root -> right);
    cout<<root -> data<<" ";
}

//level order
void levelOrder(Node *root){
    if(root == NULL){
        return;
    }

    queue<Node*> Q;
    Q.push(root);

    while(!Q.empty()){
        Node *curr = Q.front();
        Q.pop();

        cout<<curr -> data<<" ";

        if(curr -> left != NULL){
            Q.push(curr -> left);
        }

        if(curr -> right != NULL){
            Q.push(curr-> right);
        }
        // cout<<endl;
    }
}
//height of the tree
int height(Node *root){
    if(root == NULL){
        return 0;
    }
    int leftHT = height(root -> left);
    int rightHT = height(root -> right);

    int currHT = max(leftHT,rightHT) + 1;
    return currHT;
}

//count Nodes
int count(Node *root){
    if(root == NULL){
        return 0;
    }

    int leftCount = count(root -> left);
    int rightCount = count(root -> right);
    return leftCount + rightCount + 1;
}

//tree sum
int sum(Node *root){
    if(root == NULL){
        return 0;
    }

    int leftSum = sum(root -> left);
    // int currRoot = root -> data;
    int rightSum = sum(root ->right);
    int currSum = leftSum + + rightSum + root -> data;
    cout<<"currSum: "<<currSum<<endl;
    return currSum;

}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(nodes);
    // cout << "root = " << root->data << endl;

    // preorder(root);
    // cout<<endl;

    // inOrder(root);f
    // cout<<endl;

    // postOrder(root);
    // cout<<endl;

    // levelOrder(root); // 1 2 3 4 5 6

    // cout<<"height: "<< height(root)<<endl;

    // cout<<"Total Nodes: "<<count(root)<<endl;
    // Node *root2 = new Node(5);
    // root2 -> left = new Node(3);
    // root2 -> right = new Node(4);
    // cout<< "Count2 : "<<count(root2)<<endl;

    cout<<"Sum : "<<sum(root)<<endl;


    return 0;
}
