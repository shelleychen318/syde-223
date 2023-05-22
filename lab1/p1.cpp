#include <iostream>
using namespace std;
#define MAX_SIZE 500 // maximum size of the string

int main()
{
    // string input;
    // int *p;
    // p = new int();
    // cout << "Enter input: ";
    // cin >> input;
    // *p = input.size();
    // cout << *p;

    // delete p;
    // p = NULL;


    char text[MAX_SIZE];
    char * str = text; // points to the first character of the array
    int count = 0;

    cout << "Enter input: ";
    cin >> text;

    while ( *(str++) != '\0') {
        count++;
    }

    cout << count;

    // delete str;
    // str = NULL;
}