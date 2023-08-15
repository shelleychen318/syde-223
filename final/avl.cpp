#include <iostream>
template <typename T>

struct AVLNode
{
    T data;
    AVLNode *left;
    AVLNode *right;
    int height;
    AVLNode(const T &value) : data(value), left(nullptr), right(nullptr), height(1) {}
};
template <typename T>

class AVLTree
{
private:
    AVLNode<T> *root;

    int getHeight(AVLNode<T> *node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int getBalance(AVLNode<T> *node)
    {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    AVLNode<T> *rotateLeft(AVLNode<T> *node)
    {
        AVLNode<T> *newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        newRoot->height = 1 + std::max(getHeight(newRoot->left), getHeight(newRoot->right));
        return newRoot;
    }

    AVLNode<T> *rotateRight(AVLNode<T> *node)
    {
        AVLNode<T> *newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        newRoot->height = 1 + std::max(getHeight(newRoot->left), getHeight(newRoot->right));
        return newRoot;
    }

    AVLNode<T> *insertHelper(AVLNode<T> *node, const T &value)
    {
        if (node == nullptr)
        {
            return new AVLNode<T>(value);
        }
        if (value < node->data)
        {
            node->left = insertHelper(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertHelper(node->right, value);
        }
        else
        {
            // Duplicate values are not allowed in AVL tree, handle accordingly
            return node;
        }
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);
        // Left-Left case
        if (balance > 1 && value < node->left->data)
        {
            return rotateRight(node);
        }
        // Right-Right case
        if (balance < -1 && value > node->right->data)
        {
            return rotateLeft(node);
        }
        // Left-Right case
        if (balance > 1 && value > node->left->data)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        // Right-Left case
        if (balance < -1 && value < node->right->data)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

public:
    AVLTree() : root(nullptr) {}
    void insert(const T &value)
    {
        root = insertHelper(root, value);
    }
};

int main()
{
    AVLTree<int> avlTree;
    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(30);
    avlTree.insert(40);
    avlTree.insert(50);
    avlTree.insert(25);
    return 0;
}