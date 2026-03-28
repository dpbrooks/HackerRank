/*
 * Use an array to store a number of ints then print the ints in reverse order
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int size;
    scanf("%d", &size);
    int arr[size];
    int temp;
    // Populate the array
    for(int i = 0; i < size; i++) {
        scanf("%d", &temp);
        arr[i] = temp;
    }
    // Print the array in reverse order
    for(int i = size - 1; i >= 0; i--) {
        cout<<arr[i]<<" ";
    }
    return 0;
}
