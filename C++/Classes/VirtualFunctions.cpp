/*
 * Store and print info about professors and students
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Global variables to track number of Profs and Students
static int numProf = 0;
static int numStud = 0;

class Person {
    
    private:
        string name;
        int age;
        
    public:
        // Getters
        string get_name() {
            return name;
        }
        
        int get_age() {
            return age;
        }
        
        // Setters
        void set_name(string name) {
            this->name = name;
        }
        
        void set_age(int age) {
            this->age = age;
        }
        
        virtual void getdata() {}
        
        virtual void putdata() {}
};

class Professor : public Person {
    
    private:
        int publications, cur_id;
        
    public:
        // Get name, age, and publications from user
        void getdata() {
            string nme;
            int age;
            cin >> nme >> age >> publications;
            this->set_name(nme);
            this->set_age(age);
            
            numProf++;
            cur_id = numProf;
        }
        
        // Print name, age, publications, and cur_id
        void putdata() {
            cout << this->get_name() << " " << this->get_age() << " " 
            << publications << " " << cur_id << endl;
        }
};

class Student : public Person {
    
    private:
        vector<int> marks;
        int cur_id;
        
    public:
        // Get name, age, and marks from user
        void getdata() {
            string nme;
            int age;
            cin >> nme >> age;
            this->set_name(nme);
            this->set_age(age);
            int temp;
            for (int i = 0; i < 6; i++) {
                cin >> temp;
                marks.push_back(temp);
            } 
            
            numStud++;
            cur_id = numStud;
        }   
        
        int marks_sum() {
            int sum = 0;
            for (int i = 0; i < marks.size(); i++) {
                sum += marks[i];
            }
            return sum;
        }
        
        // Print name, age, sum of the marks and cur_id
        void putdata() {
            cout << this->get_name() << " " << this->get_age() << " "
            << marks_sum() << " " << cur_id << endl;
        }
};

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
