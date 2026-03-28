/*
 * Use vectors to take in an unknown number of lists of numbers.
 * Then, use the stored lists to answer queries that ask for what is
 * stored at specific locations
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    // First line takes in length of main array and # of queries
    int mainSize, numQ;
    scanf("%d %d", &mainSize, &numQ);
    std::vector<std::vector<int>> mainArr;
    /* Then construct sub-arrays, first number of each new line
    is the size of the sub-array*/ 
    int subSize;
    for (int i = 0; i < mainSize; i++) {
        std::vector<int> subArr;
        scanf("%d", &subSize);
        subArr.resize(subSize);
        for (int j = 0; j < subSize; j++) {
            scanf("%d", &subArr[j]);
        }
        mainArr.push_back(subArr);
    }
    // Read queries and print results
    int a, b;
    for (int i = 0; i < numQ; i++) {
        cin>>a>>b;
        cout<<mainArr[a][b]<<endl;
    }
    return 0;
}
