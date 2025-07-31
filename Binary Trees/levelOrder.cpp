#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Node definition
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

// Build tree from preorder vector with -1 as null
Node* buildTree(vector<int>& nodes) {
    idx++;
    if (nodes[idx] == -1) return NULL;

    Node *currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);
    return currNode;
}

// Level order traversal with line breaks
void levelOrder(Node *root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL); // level marker

    while (!q.empty()) {
        Node *curr = q.front();
        q.pop();

        if (curr == NULL) {
            cout << endl;
            if (!q.empty()) q.push(NULL);
        } 
        
        else {
            cout << curr->data << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(nodes);

    levelOrder(root); // Output: 1 \n 2 3 \n 4 5 6

    return 0;
}
