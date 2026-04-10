/*
 * Creates a vector of input numbers and prints them after sorting
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<int> vect;
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        vect.push_back(temp);
    }
    
    sort(vect.begin(), vect.end());
    
    for (int i = 0; i < n; i++) {
        cout << vect[i] << " ";
    }
    return 0;
}
