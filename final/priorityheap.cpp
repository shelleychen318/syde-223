#include <iostream>
#include <vector>

template <typename T>
class PriorityMaxHeap
{
private:
    std::vector<T> heap;

    void heapifyUp(int index)
    {
        // Calculate the parent index for the current node
        int parent = (index - 1) / 2;

        // Keep swapping the node with its parent until heap property is satisfied
        while (index > 0 && heap[index] > heap[parent])
        {
            std::swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index)
    {
        // Calculate the left and right child indices for the current node
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        // Assume the current index is the largest among its children
        int largest = index;

        // Check if the left child exists and if it's greater than the current largest
        if (leftChild < heap.size() && heap[leftChild] > heap[largest])
        {
            largest = leftChild;
        }

        // Check if the right child exists and if it's greater than the current largest.
        if (rightChild < heap.size() && heap[rightChild] > heap[largest])
        {
            largest = rightChild;
        }

        // If the largest node is not the current node, swap them and continue heapifying down.
        if (largest != index)
        {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    PriorityMaxHeap() {}

    // Function to insert a new element into the max heap.
    void insert(const T &value)
    {
        heap.push_back(value);      // Add the new element to the end of the heap.
        heapifyUp(heap.size() - 1); // Restore the heap property by moving the new element up the heap.
    }

    // Function to extract the maximum element (root) from the max heap.
    T extractMax()
    {
        if (heap.empty())
        {
            throw std::out_of_range("Heap is empty.");
        }

        T maxElement = heap[0]; // Store the maximum element (root) to return later.
        heap[0] = heap.back();  // Replace the root with the last element in the heap.
        heap.pop_back();        // Remove the last element from the heap (former root).
        heapifyDown(0);         // Restore the heap property by moving the new root down the heap.
        return maxElement;      // Return the maximum element that was extracted.
    }

    // Function to check if the heap is empty.
    bool isEmpty() const
    {
        return heap.empty();
    }
};

int main()
{
    PriorityMaxHeap<int> priorityMaxHeap; // Create an instance of PriorityMaxHeap with int type.

    // Insert elements into the heap.
    priorityMaxHeap.insert(10);
    priorityMaxHeap.insert(20);
    priorityMaxHeap.insert(5);
    priorityMaxHeap.insert(15);

    // Extract and print the maximum element from the heap until it's empty.
    while (!priorityMaxHeap.isEmpty())
    {
        std::cout << priorityMaxHeap.extractMax() << " ";
    }
}
