#include <iostream>
using namespace std;

void insertion_sort(int arr[] , int n) {
    for(int i = 1; i < n;i++) {
        int curr = arr[i];
        int prev = i-1;
        while(prev >=0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev];
            prev--; 
        }
        arr[prev+1] = curr;
    }
}

void print(int arr[], int n) {
    for(int i =0; i <n ;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {4,1,5,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "before insertion sort "<< endl;
    print(arr,n);
    insertion_sort(arr,n);
    cout << "after insertion sort "<< endl;
    print(arr,n);
}