#include<iostream>
using namespace std;

int partitionIndex(int arr[], int s, int e) {
    int i = s - 1;
    int j = e + 1;
    int pivot = arr[s];  // Using first element as pivot
    
    while(true) {
        while(arr[++i] < pivot);
        while(arr[--j] > pivot);
        
        if(i >= j) {
            return j;
        }
        swap(arr[i], arr[j]);
    }
}

void quickSort(int arr[], int s, int e) {
    if(s >= e) {
        return;
    }
    int pivotIndex = partitionIndex(arr, s, e);
    quickSort(arr, s, pivotIndex);
    quickSort(arr, pivotIndex + 1, e);
}

int main() {
    int arr[] = {10, 90, 49, 2, 1, 5, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}