/******************************************************************************
Name: Shelley Chen
Student ID: 21002650
Date: June 4, 2022
Course: SYDE 223
Assignment #1
Program Description: This is a program that implements a circular linked list 
to store and manipulate a collection of integers. It includes features such as
insertion, deletion, display, and searching.
*******************************************************************************/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head; 

public:
    // default constructor
    CircularLinkedList() : head(nullptr) {}

    // inserts new node at the end of circular linked list
    void insertAtEnd(int newData) {
        // create new node
        Node* newNode = new Node; 
        newNode->data = newData;

        // if list is empty, make head point to new node
        if (!head) {
            head = newNode;
            newNode->next = newNode;
        }
        else {
            Node* current = head; 

            // traverse through the list until we reach the end
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode; // make old end node point to new one
            newNode->next = head; // make new node point to head
        }
    }

    // delete last occurrence of a given integer in circular linked list
    void deleteNode(int deleteData) {
        // if list is empty, immediately return 
        if (!head) {
            cout << "Circular linked list is empty. Deletion failed." << endl;
            return;
        }

        // pointers to find the last occurrence of given integer value
        Node* current = head;
        Node* prev = nullptr;
        Node* lastOccurrence = nullptr;
        Node* lastOccurrencePrev = nullptr;

        // traverse through entire list
        do {
            // keep track of the last occurrence of node to delete and its previous node
            if (current->data == deleteData) {
                lastOccurrence = current;
                lastOccurrencePrev = prev;
            }

            // update pointers
            prev = current;
            current = current->next;
        } while (current != head);

        // if given integer does not exist in list
        if (!lastOccurrence) {
            cout << deleteData << " does not exist in the circular linked list. Deletion failed." << endl;
            return;
        }

        // if node to be deleted is head
        if (lastOccurrence == head) {
            // traverse to actual last node
            while (current->next != head) {
                current = current->next;
            }
            // update pointers
            current->next = head->next; 
            head = head->next;
        }
        else {
            lastOccurrencePrev->next = lastOccurrence->next;
        }
        delete lastOccurrence;
        cout << "Last occurrence of " << deleteData << " deleted successfully." << endl;
    }

    // displays all the nodes in the circular linked list in a clockwise direction
    void display() {
        Node* current = head;

        if (!head) {
            cout << "Circular linked list is empty." << endl;
            return;
        }
        else {
            cout << "Nodes of the circular linked list:" << endl;

            // print each node by incrementing pointer until last node is reached
            do {
                cout << current->data << " ";
                current = current->next;
            } while (current != head);
            cout << endl;
        }
    }

    // searches for a given integer in the circular linked list and returns its position (index)
    int search(int searchData) {
        Node* current = head;
        int index = 0;

        if (!head) {
            cout << "Circular linked list is empty. Search failed." << endl;
            return -1;
        }

        // iterate through the list until integer is found
        while (current->data != searchData) {
            current = current->next;
            index++;
        }
        return index;
    }
};

int main() {
    CircularLinkedList list;

    // added nodes with values 1, 2, 3, 2 to list
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(2);

    // list will be 1 2 3 2
    list.display();

    // delete last occurrence of 2
    list.deleteNode(2);

    // list will be 1 2 3
    list.display();

    // 2 is in position 1 of the list
    cout << list.search(2) << endl;
}
