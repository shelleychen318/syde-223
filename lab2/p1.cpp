#include<iostream>
using namespace std;

class Student {
    string name;

    public:
        Student(string name);
        string get_name();
};

// constructor function
Student::Student(string name) {
    this->name = name;
}

string Student::get_name() {
    return name;
}

int main () {
    Student* shelley = new Student("Shelley"); // create a pointer that points to Student object
    cout << shelley->get_name(); // use arrow operator to access member functions
}