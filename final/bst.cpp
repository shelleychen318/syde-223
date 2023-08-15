#include <iostream>

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
private:
    Node *root;

public:
    BST()
    {
        root = nullptr;
    }

    // Recursive function to insert a new node into the BST
    Node *insert(Node *root, int val)
    {
        if (root == nullptr)
        {
            // Create a new node if the current node is null
            return new Node(val); 
        }
        if (val < root->data)
        {
            // Recursively insert into the left subtree
            root->left = insert(root->left, val); 
        }
        else if (val > root->data)
        { 
            // Recursively insert into the right subtree
            root->right = insert(root->right, val);
        }
        return root;
    }

    // Public function to insert a new node into the BST
    void insert(int val)
    {
        root = insert(root, val); // Call the private insert function with the root as the starting point
    }

    // Recursive function to find the node with the maximum value in the BST
    Node *findMaxNode(Node *root)
    {
        if (root == nullptr)
        {
            // Return null if the current node is null (empty tree)
            return nullptr; 
        }
        while (root->right != nullptr)
        {
            // Traverse to the rightmost node to find the maximum value in the BST
            root = root->right; 
        }
        return root;
    }

    // Public function to find the maximum value in the BST
    int findMax()
    {
        Node *maxNode = findMaxNode(root); // Call the private findMaxNode function
        if (maxNode == nullptr)
        {
            std::cerr << "Error: Tree is empty." << std::endl;
            return -1; 
        }
        return maxNode->data; 
    }

    // Recursive function to delete a node with a given key from the BST
    Node *deleteNode(Node *root, int key)
    {
        if (root == nullptr)
        {
            return root;
        }
        if (key < root->data)
        {
            // Recursively delete the node from the left subtree
            root->left = deleteNode(root->left, key); 
        }
        else if (key > root->data)
        {
            // Recursively delete the node from the right subtree
            root->right = deleteNode(root->right, key);
        }
        else
        {
            // If the node has only one child or no child, replace the node with its right child
            if (root->left == nullptr)
            {
                Node *temp = root->right;
                delete root;
                return temp; 
            }
            else if (root->right == nullptr)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            Node *successor = findMaxNode(root->left);            // If the node has two children, find the maximum value in its left subtree
            root->data = successor->data;                         // Replace the node's data with the inorder predecessor's data
            root->left = deleteNode(root->left, successor->data); // Recursively delete the inorder predecessor node from the left subtree
        }
        return root;
    }

    // Public function to delete a node with a given key
    void deleteNode(int key)
    {
        root = deleteNode(root, key); // Call the private deleteNode function
    }
};

int main()
{
    BST bst; // Create a binary search tree object

    // Insert elements into the binary search tree
    bst.insert(15);
    bst.insert(8);
    bst.insert(25);
    bst.insert(4);
    bst.insert(12);
    bst.insert(18);
    bst.insert(30);
    bst.insert(10);
    bst.insert(14);
    bst.insert(22);

    int maxElement = bst.findMax();
    std::cout << "The maximum element in the BST is: " << maxElement << std::endl;

    // Delete nodes from the BST 
    bst.deleteNode(18);
    bst.deleteNode(12);

    return 0;
}
