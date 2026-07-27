#include <iostream>
#include <vector>
using namespace std;


class Node{
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
Node* buildtree(vector<int> nums) {
    idx++;
    if(nums[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(nums[idx]);
    root->left = buildtree(nums);
    root->right = buildtree(nums);

    return root;

}


int main() {
    vector<int> nums = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildtree(nums);

    return 0;

}