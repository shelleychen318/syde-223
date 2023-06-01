#include <iostream>

// Node structure
struct Node {
    int data;
    Node* next;
};

// Linked list class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor
    ~LinkedList() {
        // Free memory by deleting all nodes
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Method to insert a node after a given data point
    void insertAfter(int searchData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == searchData) {
                // Found the desired data point
                Node* newNode = new Node;
                newNode->data = newData;
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }

        std::cout << "Data " << searchData << " not found in the linked list." << std::endl;
    }

    // Method to search for a specific node and delete it
    void deleteNode(int searchData) {
        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->data == searchData) {
                // Found the desired node
                if (prev == nullptr) {
                    // If the node to be deleted is the head node
                    head = current->next;
                } else {
                    // If the node to be deleted is not the head node
                    prev->next = current->next;
                }
                delete current;
                std::cout << "Node with data " << searchData << " deleted from the linked list." << std::endl;
                return;
            }
            prev = current;
            current = current->next;
        }

        std::cout << "Node with data " << searchData << " not found in the linked list." << std::endl;
    }

    // Method to print the linked list
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Method to add a node at the beginning of the linked list
    void addNode(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
};

int main() {
    LinkedList myList;

    // Add nodes with data values 2, 4, 6, 8, 10
    myList.addNode(10);
    myList.addNode(8);
    myList.addNode(6);
    myList.addNode(4);
    myList.addNode(2);

    std::cout << "Linked list: ";
    myList.printList();

    // Insert a node after data value 6
    myList.insertAfter(6, 7);
    std::cout << "After inserting 7 after 6: ";
    myList.printList();

    // Delete node with data value 8
    myList.deleteNode(8);
    std::cout << "After deleting node with data 8: ";
    myList.printList();

    // Delete node with data value 5 (which doesn't exist)
    myList.deleteNode(5);

    return 0;
}