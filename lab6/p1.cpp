#include <stack>
#include <iostream>

using namespace std;

struct Qnode {
    int data;
    Qnode* next;
};

class Queue {
    private:
        int size;
    
    public:
        Queue() {
            size = 0;
        }
    
    
        void enqueue(int value) 
        {
        }
    
        int dequeue() 
        {
        }
        
        int peek() 
        {
        }
        
        bool empty() 
        {
        }
};


class QStack {
    private:
        Queue *queue_main;
        Queue *queue_aux;
    
    public:
        QStack() {
            queue_main = new Queue();
            queue_aux = new Queue();
        }
    
        int pop() 
        {
        }
        
        void push(int value) 
        {
        }
    
        bool empty() 
        {
        }
        
        int top() 
        {
        }
};


void FNLE(int arr[], int size){
    QStack s;
    
}

int main()
{
    // Question 1 Test Cases
    cout << "Q1 Test case 1: " << endl;
    Queue *testQueue = new Queue();
    testQueue->enqueue(0);
    cout << "Dequeued: " << testQueue->dequeue() << endl;
    testQueue->dequeue();
    testQueue->enqueue(4);
    testQueue->enqueue(1);
    testQueue->enqueue(2);
    cout << "Dequeued: " << testQueue->dequeue() << endl;
    testQueue->enqueue(3);
    while (!testQueue->empty())
    {
        cout << "Remaining: " << testQueue->dequeue() << endl;
    }
    

    // Question 2 Test Cases
//    cout << endl << "Q2 Test case 1: " << endl;
//    QStack *testStack = new QStack();
//    testStack->push(9);
//    testStack->push(5);
//    cout << "Dequeued: " << testStack->pop() << endl;
//    cout << "Dequeued: " << testStack->pop() << endl;
//    testStack->push(4);
//    testStack->push(3);
//    testStack->push(2);
//    testStack->push(1);
//    while (!testStack->empty())
//    {
//        cout << "Remaining: " << testStack->pop() << endl;
//    }
        

    // Question 3 Test Cases
//    cout << endl << "Q3 Test case 1: " << endl;
//    int arr1[] = {6,4,12,3,5,1};
//    FNLE(arr1, 6);
//
//    cout << "Q3 Test case 2: " << endl;
//    int arr2[] = {1,2,3,4,5,6,7,8};
//    FNLE(arr2, 8);
//
//    cout << "Q3 Test case 3: " << endl;
//    int arr3[] = {8,7,6,5,4,3,2,1};
//    FNLE(arr3, 8);
//
//    cout << "Q3 Test case 4: " << endl;
//    int arr4[] = {5,1,3,2,7,4,9,3};
//    FNLE(arr4, 8);
    
    return 0;
}
