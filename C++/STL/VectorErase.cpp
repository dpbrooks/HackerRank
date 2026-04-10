/*
 * Practice using the erase function for vectors
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
    int n, temp, pos1, pos2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        vect.push_back(temp);
    }
    // Single erase
    cin >> pos1;
    vect.erase(vect.begin() + pos1 - 1);
    
    // Range erase
    cin >> pos1 >> pos2;
    vect.erase(vect.begin() + pos1 - 1, vect.begin() + pos2 - 1);
    
    cout << vect.size() << endl;
    for (int i = 0; i < vect.size(); i++) {
        cout << vect[i] << " ";
    }
    return 0;
}
