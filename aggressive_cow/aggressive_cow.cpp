/* 
Aggressive Cows Problem
Assign C cows to N stalls such that min distance between them is largest possible.
Return largest minimum distance.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool isPossible(vector<int> &arr, int c, int minAllowed,int n) {
    int cow = 1;
    int lastStallPos = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] - lastStallPos >= minAllowed) {
            cow++;
            lastStallPos = arr[i];
        }

        if(c == cow) {
            return true;
        }
    }
    return false;
}

int max_distance(vector<int> &arr, int c,int n) {
    sort(arr.begin() , arr.end());
    int st = 1;
    int end = arr[n-1] - arr[0];
    int ans = -1;

    while(st<=end) {
        int mid = st + (end-st)/2;
        
        if(isPossible(arr,c,mid,n)) {
            ans = mid;
            st = mid+1;
        }else {
            end = mid-1;
        }

    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 8, 4, 9};
    int n = arr.size();
    int c = 3;

    cout << max_distance(arr,c,n);


}