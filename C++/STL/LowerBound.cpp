/*
 * Practice using lower bound in vectors
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    // Build vector  
    vector<int> vect;
    int n, temp, q, q_num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        vect.push_back(temp);
    } 
    
    // Work on queries
    cin >> q;
    vector<int>::iterator low;
    for (int i = 0; i < q; i++) {
        cin >> q_num;
        low = lower_bound(vect.begin(), vect.end(), q_num);
        // Add one to the index because output should be index 1 based instead of 0
        if (vect[low - vect.begin()] == q_num) {
            cout << "Yes " << low - vect.begin() + 1 << endl;
        } else {
            cout << "No " << low - vect.begin() + 1 << endl;
        }
    }
    return 0;
}
