/*
Painter's Partition Problem

Given are N boards of length of each given in the form of array, and M painters, such that each painter
takes 1 unit of time to paint 1 unit of the board.

The task is to find the minimum time to paint all boards under the constraints that any
painter will only paint continuous sections of boards
*/

#include <iostream>
#include <vector>
#include<climits>
using namespace std;

bool isValid(vector<int> &arr, int m , int mid) {
    int work = 0;
    int painter = 1;

    for(int i = 0; i <= arr.size()-1; i++) { /* its to check it the maximum  work for one painter (mid) is valid or not */
        if(arr[i] > mid) {
            return false;
        }

        if(work + arr[i] <= mid){
            work = work + arr[i];
        }else {
            painter++;
            work = arr[i];
        }
    }
    return painter > m ? false : true;
}


int min_time(vector<int> &arr , int m){
    
    int sum = 0;
    int maxVal = INT_MIN; /* we do this to make the search space more optimised that why we dont start from st = 0
    as st = 40 is the minium time maximum time requires to compelte by one painter so the average will
    always be greater that maxVal*/

    for(int i =0; i <= arr.size()-1; i++) {
        sum  = sum + arr[i];
        maxVal = max(maxVal, arr[i]);
    }

    int st = maxVal;
    int end = sum;
    int time = -1;

    while(st<=end) {
        int mid = st + (end-st)/2;

        if(isValid(arr, m, mid)) {
            time = mid;  
            end = mid -1; /* we search in left side (left side values are small) means we need min value of 
            time  */ // here we are trying to find is there any min value than this that we can find 
            /*mid is the maximum time for each person but we need min so se search in left side*/
        }else {
            st = mid+1;
        }
    }

    return time;

}

int main() {
    vector<int> arr = {40,30,10,20};
    int m = 2;
    
    cout << min_time(arr,m);

}