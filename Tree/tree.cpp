#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data; // stores value in the node of the tree
    Node* left;  // stores left child's address
    Node* right; // stores right child's address

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

static int idx = -1;

Node* BuildTree(vector<int> preorder) {  // return type is Node* because this function creates Node objects and returns their address
    idx++;                             // move to next element in preorder before reading it
    if(preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]); // creates a new Node object in memory; root stores its address
    root->left = BuildTree(preorder);
    root->right = BuildTree(preorder);

    return root;
}

int main() {
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = BuildTree(preorder); 
    // root now holds the address of the top of the built tree
    cout << root->data << " ";
    cout << root->left->data << " ";
    cout << root->right->data << " ";
}

// here output wil be 1 2 3 ;