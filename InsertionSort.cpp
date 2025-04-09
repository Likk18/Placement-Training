#include<iostream>
using namespace std;

int merge(int arr[], int left, int mid, int right) {
    int invCount = 0;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    int* temp1 = new int[n1];
    int* temp2 = new int[n2];
    
    // Copy data to temporary arrays
    for(int i = 0; i < n1; i++)
        temp1[i] = arr[left + i];
    for(int j = 0; j < n2; j++)
        temp2[j] = arr[mid + 1 + j];
    
    // Merge the temporary arrays back
    int i = 0;    // Index for first subarray
    int j = 0;    // Index for second subarray
    int k = left; // Index for merged array
    
    while(i < n1 && j < n2) {
        if(temp1[i] <= temp2[j]) {
            arr[k++] = temp1[i++];
        } else {
            arr[k++] = temp2[j++];
            invCount += (n1 - i); // Count inversions
        }
    }
    
    // Copy remaining elements of temp1[]
    while(i < n1) {
        arr[k++] = temp1[i++];
    }
    
    // Copy remaining elements of temp2[]
    while(j < n2) {
        arr[k++] = temp2[j++];
    }
    
    // Free temporary arrays
    delete[] temp1;
    delete[] temp2;
    
    return invCount;
}

int mergeSort(int arr[], int left, int right) {
    int invCount = 0;
    if(left < right) {
        int mid = left + (right - left) / 2; // Avoid integer overflow
        invCount += mergeSort(arr, left, mid);
        invCount += mergeSort(arr, mid + 1, right);
        invCount += merge(arr, left, mid, right);
    }
    return invCount;
}

int main() {
    int arr[] = {5, 3, 2, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count = mergeSort(arr, 0, n-1);
    
    cout << "Inversion Count: " << count << endl;
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}