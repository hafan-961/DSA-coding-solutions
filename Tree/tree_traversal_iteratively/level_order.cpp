#include <iostream>
#include <queue>
using namespace std;

class Node {
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

void levelorder(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(q.size() > 0) {
        
        int size = q.size();

        for(int i = 0 ; i < size ; i++) {
            Node* node = q.front();    //adding hte front elemnt in the node 
            q.pop();  //deleting the fist element in queue

            if(node->left != NULL){
                q.push(node->left);   // adding left element of root to queue
            }
            if(node->right != NULL) {
                q.push(node->right);   //adding right element of root to queue
            }

            cout << node->data << " ";  // printin the root 
        }
    }

}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    levelorder(root);

    return 0;
}