#include <iostream>
#include <vector>
using namespace std;

void move_zero(vector<int> &nums, int n) {
    int index = 0;
    for(int i = 0 ; i < n ; i++) {
        if(nums[i] != 0) {
            swap(nums[index], nums[i]);
            index++;
        }
    }
}

void print(vector<int> &nums) {
    for(int x : nums) {
        cout << x << " ";
    }
}

int main() {
    vector<int> nums = {2,0,0,0,4,6};
    int n = nums.size();
    move_zero(nums, n);
    print(nums);
}