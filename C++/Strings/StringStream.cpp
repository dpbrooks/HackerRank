/*
 * Use stringstream to parse a set of ints seperated by commas (ex. "23,4,56")
 * Print the integers on their own lines
 */
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    vector<int> nums;
    stringstream ss(str);
    char ch;
    int num;
    // Continues to loop while there are still ints to read in the stream
    while(ss>>num) {
        nums.push_back(num);
        // Takes in the comma so the next int can be read in the next loop
        ss>>ch;
    }
    return nums;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
