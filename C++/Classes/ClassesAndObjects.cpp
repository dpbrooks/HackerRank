/*
 * Compares the sum of test scores of students to the scores of the first.
 * Prints the number of students that scored higher
 * Changed slightly from HackerRank scenario to handle any specefied number
 * of test scores instead of only 5
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// Write your Student class here
class Student {
  private:
    // Use a vector to store the test scores
    vector<int> scores;
    
  public:
    // Read student scores and save
    void input(int num_scores) {
        int score;
        for (int i = 0; i < num_scores; i++) {
            cin >> score;
            scores.push_back(score);
        }
    }
    
    // Calculates the sum of the student's test scores
    int calculateTotalScore() {
        int sum = 0;
        for (int i = 0; i < scores.size(); i++) {
            sum += scores[i];
        }
        return sum;
    }
};

int main() {
    int n, num_scores; // number of students
    cin >> n >> num_scores;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input(num_scores);
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}
