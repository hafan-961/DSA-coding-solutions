/* this is for checking if the given tree is binary search tree or not ?*/

#include <iostream>
#include <vector>
using namespace std;
class Node{  //defining structure of the tree
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};

static int idx = -1;
Node* BuildTree(vector<int> tree){   //Building the tree 
    idx++;
    if(tree[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(tree[idx]);
    root->left = BuildTree(tree);
    root->right = BuildTree(tree);

    return root;
}

int findmax(Node* root) { //finding the max element in left subtree
    if(root == NULL) {
        return INT_MIN;
    }

    while(root->right != NULL) {
        root = root->right;
    }
    return root->data;
}


int findmin(Node* root) {  // finding the min element in right subtree
    if(root == NULL) {
        return INT_MAX;
    }

    while(root->left != NULL) {
        root = root->left;
    }

    return root->data;
}
bool isBst(Node* root) {
    if(root == NULL) {
        return true;
    }

    bool isleftbst = isBst(root->left);   // checks if left subtree is valid bst or not 
    bool isrightbst = isBst(root->right);  // checks if right subtree is valid bst or not 

    int maxleft = findmax(root->left);   // getting the max element
    int minright = findmin(root->right); //getting the min element 

    if(isleftbst && isrightbst && maxleft < root->data &&  minright > root->data) {  //if every condition is correct then its bst
        return true;
    }
    return false;

}


int main() {
    vector<int> tree = {10, 5, -1, 9, -1, -1, 20, 11, -1, -1, -1};
    Node* root = BuildTree(tree);
    cout << isBst(root);
}






















