#include <iostream>
using namespace std;

void QuickSort(int A[], int indexLeft, int indexRight);

void QuickSort(int A[], int indexLeft, int indexRight)
{
    // Input check. If any index < 0, or indexLeft >= indexRight, do nothing.
    if (indexLeft < 0 || indexRight < 0)
        return;
    if (indexLeft >= indexRight)
        return;

    int indexPivot = indexLeft;

    // Use two indices, x and y, to iterate through the array
    int x, y;
    x = indexLeft + 1;
    y = indexRight;

    int temp;
    while (true)
    {
        // Move x one element at a time to right until it reaches an element whose value is greater than the pivot or until it reaches indexRight + 1
        //  so all the items index < x will be no larger than pivot.
        while (A[x] <= A[indexPivot] && x < indexRight + 1)
            x++;

        // If x reaches or passes y, break the loop.
        if (x >= y)
            break;

        // If not break, move y one element at a time to left until it reaches an element whose value is smaller than the pivot or until it reaches x
        while (A[y] >= A[indexPivot] && y > x)
            y--;

        // If y reaches x, break the loop.
        if (x == y)
            break;

        // If not break, swap x and y values, and continue the loop
        temp = A[x];
        A[x] = A[y];
        A[y] = temp;
    }

    // Move the pivot point to the proper location. (i.e., x - 1)
    if (indexPivot != x - 1)
    {
        temp = A[indexPivot];
        A[indexPivot] = A[x - 1];
        A[x - 1] = temp;

        indexPivot = x - 1;
    }

    for (int k = indexLeft; k <= indexRight; k++)
    {
        cout << A[k] << ", ";
    }
    cout << endl;

    // Recursively, quick sort the values on the left of pivot.
    QuickSort(A, indexLeft, indexPivot - 1);

    // Recursively, quick sort the values on the right of pivot.
    QuickSort(A, indexPivot + 1, indexRight);
}
