#include<iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int target) {
    while (left < right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            right = mid + 1;
        }
        else {
            left = mid - 1;
        }
    }

    return -1;
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    int fib_prev = 0;
    int fib_current = 1;
    int fib_next;

    for (int i = 2; i <= n; i++) {
        fib_next = fib_prev + fib_current;
        fib_prev = fib_current;
        fib_current = fib_next;
    }
    return fib_current;
}

int main() {
    cout << fibonacci(9);

    return 0;
}

