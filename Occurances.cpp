#include<iostream>
using namespace std;
int firstoccurance(int arr[],int n ,int key)
{
    int s = 0;
    int e = n-1;
    int ans =-1;
    while(s<e){
        int mid = s + (e-s)/2;
        if(arr[mid] == key){
            ans = mid;
            e = mid - 1; // search in left half
        }
        else if(arr[mid] < key){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    
    }
    return ans;
}
int lastoccurance(int arr[],int n ,int key)
{
    int s = 0;
    int e = n-1;
    int ans =-1;
    while(s<e){
        int mid = s + (e-s)/2;
        if(arr[mid] == key){
            ans = mid;
            s = mid + 1; // search in right half
        }
        else if(arr[mid] < key){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    
    }
    return ans;
}
int totaloccurance(int arr[],int n ,int key)
{
    int first = firstoccurance(arr,n,key);
    if(first == -1){
        return 0;
    }
    int last = lastoccurance(arr,n,key);
    return (last - first + 1);
}
int main()
{
    int arr[] = {1, 2, 2, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 2;
    cout << "First Occurrence: " << firstoccurance(arr, n, key) << endl;
    cout << "Last Occurrence: " << lastoccurance(arr, n, key) << endl;
    cout << "Total Occurrence: " << totaloccurance(arr, n, key) << endl;
    return 0;
}