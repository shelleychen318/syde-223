#include<iostream>
using namespace std;

// function that takes an integer n and prints all binary
// strings of length n in ascending order
void printNBinary(int n, string str="") {
    // base case: we are at last character of binary string
    if (n == 0) {
        cout << str << endl;
    }
    // not at last character of binary string
    else {
        // recursive calls to append next value to binary string
        printNBinary(n - 1, str + "0"); 
        printNBinary(n - 1, str + "1");
    }
};

int main () {
    printNBinary(4);
    return 0;
}