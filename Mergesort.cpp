#include<iostream>
#include<algorithm> // For std::sort
using namespace std;

void mergeAndSortArrays(int a1[], int n1, int a2[], int n2) {
    // Create merged array with dynamic size
    int totalSize = n1 + n2;
    int* a3 = new int[totalSize];
    
    // Copy first array
    int k = 0;
    for(int i = 0; i < n1; i++) {
        a3[k++] = a1[i];
    }
    
    // Copy second array
    for(int j = 0; j < n2; j++) {
        a3[k++] = a2[j];
    }
    
    // Sort the merged array
    sort(a3, a3 + totalSize);
    
    // Print the result
    cout << "Merged and sorted array: ";
    for(int i = 0; i < totalSize; i++) {
        cout << a3[i] << " ";
    }
    cout << endl;
    
    // Free allocated memory
    delete[] a3;
}

int main() {
    int a1[] = {5, 2, 8, 1, 9};    // Example unsorted array 1
    int n1 = 5;
    int a2[] = {7, 3, 6};         // Example unsorted array 2
    int n2 = 3;
    
    cout << "First array: ";
    for(int i = 0; i < n1; i++) {
        cout << a1[i] << " ";
    }
    cout << endl;
    
    cout << "Second array: ";
    for(int i = 0; i < n2; i++) {
        cout << a2[i] << " ";
    }
    cout << endl;
    
    mergeAndSortArrays(a1, n1, a2, n2);
    
    return 0;
}