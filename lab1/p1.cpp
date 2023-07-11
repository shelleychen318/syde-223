#include <iostream>
using namespace std;

int main()
{
    char text[500]; // declare char array of size 500
    char *str = text; // points to first char of array
    int count = 0;

    cout << "Enter input: ";
    cin >> text;

    while ( *(str++) != '\0') {
        count++;
    }

    cout << count;

    delete str;
    str = nullptr;
}
