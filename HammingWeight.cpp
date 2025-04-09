#include<iostream>
using namespace std;
int hammingWeight(int n) {
    int count = 0;
    while (n) {
        count += n & 1; // Increment count if the last bit is 1
        n >>= 1; // Right shift n by 1 to check the next bit
    }
    return count;
}

int main()
{
    cout<< "Hamming Weight of 11: " << hammingWeight(11) << endl; // Output: 3
    cout<< "Hamming Weight of 5: " << hammingWeight(5) << endl; // Output: 1
    cout<< "Hamming Weight of 0: " << hammingWeight(0) << endl; // Output: 0
    cout<< "Hamming Weight of 10: " << hammingWeight(10) << endl; // Output: 4 
    return 0;
}