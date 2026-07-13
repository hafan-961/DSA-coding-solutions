#include <iostream>
using namespace std;

void bubble_sort(int arr[] , int n) {
    bool ifSwap = false;
    for(int i = 0 ; i < n-1; i++) { /* n-1 because by the end no need to look the last element as 
        it will be automatically sorted when we sort all the remaining elements*/
        for(int j = 0; j< n-i-1; j++) { /* here n-1 because we after first pass we already got the max element in last so no need to sort in that 
            index so n-1 iteration */
            if(arr[j+1] < arr[j]){
                swap(arr[j] , arr[j+1]);
                ifSwap = true;
            }
        }
        if(!ifSwap) {  /* to check if its already sorted or not */
            return;
        }
    }
}

void print_array(int arr[],int n) {

    for(int i = 0; i < n;i++){
        cout << arr[i] << " ";
    }
    cout <<  endl;
}

int main() {
    int arr[] = {4,1,5,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,n);
    print_array(arr,n);
    return 0;
}