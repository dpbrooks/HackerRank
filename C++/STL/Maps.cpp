/*
 * Creates a map of students and scores and takes in queries
 * to add or erase scores as well as print scores of indicated
 * students
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q, q_type, x;
    string name;
    map<string, int> mp;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> q_type >> name;
        if (q_type == 1) {
            // Add marks to student score
            cin >> x;
            // Check if student has a score already
            if (mp.find(name) != mp.end()) {
                // Student has a pre-existing score
                mp[name] += x;
            } else {
                // Student does not have a pre-existing score
                mp.insert(make_pair(name, x));
            }
        } else if (q_type == 2) {
            // Erase marks from student
            mp.erase(name);
        } else if (q_type == 3) {
            // Print student score
            map<string, int>::iterator it = mp.find(name);
            if (it == mp.end()) {
                // Selected student not in map
                cout << "0" << endl;
            } else {
                // Selected student does exist
                cout << it->second << endl;
            }
        } else {
            // Not a known query
        }
    }
    return 0;
}



