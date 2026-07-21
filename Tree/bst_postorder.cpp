#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> result;
static int idx = -1;
Node* BuildTree(vector<int> nums) {
    idx++;
    if(nums[idx] == -1) {
        return NULL;
    }
    
    Node* root = new Node(nums[idx]);

    root->left = BuildTree(nums);
    root->right = BuildTree(nums);
    result.push_back(root->data);

    return root;
}


int main() {
    vector<int> nums = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = BuildTree(nums);
    
    for(int x : result) {
        cout << x << " ";
    }


}