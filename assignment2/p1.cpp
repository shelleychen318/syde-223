#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream in;

int main()
{
    in.open("shoe_sizes.txt");

    if (in.fail())
    {
        cout << "Input file opening failed\n";
        exit(1);
    }

    string name, shoe_size; 

    while (in >> name >> shoe_size) {  
        cout << name << " " << shoe_size << endl;
    }
    
    in.close(); // close the input stream
    
    return 0;
}