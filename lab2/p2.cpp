#include<iostream>
using namespace std;

int main () {
    int rows, cols, sum = 0;

    // declare a pointer to a pointer of type int (assign arr the memory address of a dynamically allocated array of int* pointers)
    int** arr = new int*[rows]; 

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;


    // Dynamically allocate memory for the 2D array

    // iterate over each element of the array arr, which represents the rows of the 2D array
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols]; // dynamically allocated an int array of size cols for each row 
    }

    // Prompt the user to enter the elements of the array and keep a running total of the elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element at position (" << i << ", " << j << "): ";
            cin >> arr[i][j];
            sum += arr[i][j];
        } 
    }

    cout << "The sum of all elements is " << sum << endl;

    // Deallocate the memory
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}