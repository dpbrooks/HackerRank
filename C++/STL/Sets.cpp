/*
 * Creates a set and responds to user queries to insert and
 * delete elements from the set as well as if certain numbers
 * exist in the set
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q, q_type, x;
    cin >> q;
    set<int> s;
    for (int i = 0; i < q; i++) {
        cin >> q_type >> x;
        if (q_type == 1) {
            // Add element to set
            s.insert(x);
        } else if ( q_type == 2) {
            // Delete an element from the set if it exists
            s.erase(x);
        } else if (q_type == 3) {
            set<int>::iterator it = s.find(x);
            if (it == s.end()) {
                // Element does not exist in the set
                cout << "No" << endl;
            } else {
                // Element does exist in the set
                cout << "Yes" << endl;
            }
        } else {
            // q_type does not match a known query
        }
    }   
    return 0;
}



