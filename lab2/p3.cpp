#include <iostream>
using namespace std;

class Student
{
    // private member variables
    string name;
    int ID, age;

public:
    Student(string name, int ID, int age);
    string get_name();
    int get_ID();
    int get_age();
};

// constructor function
Student::Student(string name, int ID, int age)
{
    this->name = name;
    this->ID = ID;
    this->age = age;
}

// get functions to return private member variables in main function
string Student::get_name()
{
    return name;
}

int Student::get_ID()
{
    return ID;
}

int Student::get_age()
{
    return age;
}

int main()
{
    int num_of_students;

    cout << "Enter number of students: ";
    cin >> num_of_students;

    // declare a Student pointer that points to an array of Student pointers
    Student **arr = new Student *[num_of_students];

    // iterate over each element of the array arr, which represents the rows of the 2D array
    for (int i = 0; i < num_of_students; i++)
    {
        string name;
        int ID, age;

        cout << "Enter the name of student " << i + 1 << ": ";
        cin >> name;
        cout << "Enter the ID of student " << i + 1 << ": ";
        cin >> ID;
        cout << "Enter the age of student " << i + 1 << ": ";
        cin >> age;

        arr[i] = new Student(name, ID, age); // dynamically allocate a new Student object for each row
    }

    cout << "Student information:" << endl;

    for (int i = 0; i < num_of_students; i++)
    {
        cout << "Student " << i + 1 << " information : Name: " << arr[i]->get_name() << ", ID: " << arr[i]->get_ID() << ", Age: " << arr[i]->get_age() << endl;
    }

    for (int i = 0; i < num_of_students; i++) {
        delete arr[i];
    }
    delete[] arr;

    return 0;
}