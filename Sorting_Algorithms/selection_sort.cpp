#include <iostream>
using namespace std;

void selection_sort(int arr[] , int n){
    for(int i = 0; i < n-1;i++){
        int smallestIndex = i;
        for(int j = i+1; j <n; j++) {
            if(arr[j] < arr[smallestIndex]) {
                smallestIndex = j;
            }
        }
        swap(arr[i],arr[smallestIndex]);
    }
}

void print(int arr[] , int n) {
    for(int i = 0 ; i < n ; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {4,1,5,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr,n);
    print(arr,n);
}