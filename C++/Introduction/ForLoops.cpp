/*
 * Use a for loop to process a given range of numbers
 */
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
    string s[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (i <= 9) {
            cout<<s[i-1]<<endl;
        } else if (i % 2 == 0) {
            cout<<"even"<<endl;
        } else {
            cout<<"odd"<<endl;
        }
    }
    return 0;
}