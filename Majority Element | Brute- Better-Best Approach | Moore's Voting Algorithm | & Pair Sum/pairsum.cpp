#include <iostream>
using namespace std;

vector<int> pairsum(vector<int> nums , int target , int size) {
    int i = 0;
    int j = size - 1;
    vector<int> ans;
    while(i < j) {
        int sum = nums[i] + nums[j];
        if(sum < target) {
            i++;
        }
        else if(sum > target) {
            j--;
        }
        else {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {2,7,11,15};
    int size = nums.size();
    int target = 26;

    vector<int> ans = pairsum(nums ,target ,size);
    cout << ans[0] << ", " << ans[1] << endl;

}