#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

ifstream in; // declares an input file stream object named in to handle file input operations.

struct Student
{
    string name;
    float shoe_size;
};

class StudentNode
{
public:
    string name;
    float shoe_size;
    StudentNode *leftChild;
    StudentNode *rightChild;

    // Default constructor.
    StudentNode();
    StudentNode(string name, float shoe_size) : name(name), shoe_size(shoe_size), leftChild(NULL), rightChild(NULL){};
    StudentNode *Insert(StudentNode *, string, float); // Insert function

    void Inorder(StudentNode *root);
    void traverseAndPrintNames(StudentNode *node, float &prevNumber);
    void printNamesWithSameNumber(StudentNode *root);
    StudentNode *removeDuplicates(StudentNode *root);
    void deleteSubtree(StudentNode *node);
    // void deleteTree(StudentNode *root);
};

StudentNode::StudentNode() : name(""), shoe_size(0), leftChild(NULL), rightChild(NULL) {}

// Insert function definition.
StudentNode *StudentNode::Insert(StudentNode *root, string name, float shoe_size)
{
    if (!root)
    {
        // Insert the first node, if root is NULL.
        return new StudentNode(name, shoe_size);
    }

    // Insert data.
    if (shoe_size >= root->shoe_size)
    {
        // Insert rightCChild node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process rightCChild nodes.
        root->rightChild = Insert(root->rightChild, name, shoe_size);
    }
    else if (shoe_size < root->shoe_size)
    {
        // Insert leftChild node data, if the 'value'
        // to be inserted is smaller than 'root' node data.

        // Process leftChild nodes.
        root->leftChild = Insert(root->leftChild, name, shoe_size);
    }

    // Return 'root' node, after insertion.
    return root;
}

void StudentNode::Inorder(StudentNode *root)
{
    if (!root)
    {
        return;
    }
    Inorder(root->leftChild);
    cout << root->name << " " << root->shoe_size << endl;
    Inorder(root->rightChild);
}

void StudentNode::traverseAndPrintNames(StudentNode *node, float &prevNumber)
{
    if (node)
    {
        traverseAndPrintNames(node->leftChild, prevNumber);

        // if we encounter a unique shoe size, print it out
        if (node->shoe_size != prevNumber)
        {
            cout << endl << node->shoe_size << ": ";
            prevNumber = node->shoe_size; // store this number
        }

        cout << node->name << ", "; // print out name

        traverseAndPrintNames(node->rightChild, prevNumber);
    }
}

void StudentNode::printNamesWithSameNumber(StudentNode *root)
{
    float prevNumber = -1;
    traverseAndPrintNames(root, prevNumber);
    cout << endl;
}

StudentNode *StudentNode::removeDuplicates(StudentNode *root)
{
    if (root == nullptr)
        return nullptr;

    root->leftChild = removeDuplicates(root->leftChild);
    root->rightChild = removeDuplicates(root->rightChild);

    if (root->leftChild != nullptr && root->shoe_size == root->leftChild->shoe_size)
    {
        StudentNode *temp = root->leftChild;
        root->leftChild = nullptr;
        deleteSubtree(temp);
    }

    if (root->rightChild != nullptr && root->shoe_size == root->rightChild->shoe_size)
    {
        StudentNode *temp = root->rightChild;
        root->rightChild = nullptr;
        deleteSubtree(temp);
    }

    return root;
}

void StudentNode::deleteSubtree(StudentNode *node)
{
    if (node == nullptr)
        return;

    deleteSubtree(node->leftChild);
    deleteSubtree(node->rightChild);
    delete node;

}

    int main()
    {
        in.open("shoe_sizes.txt"); // opening up the shoe size text file

        if (in.fail()) // if the file fails to open
        {
            cout << "Input file opening failed\n";
            exit(1);
        }

        StudentNode tree, *root = NULL;
        Student shoe_sizes[20];
        string name;
        string shoe_size;

        for (int i = 0; i < 20; i++)
        {
            in >> name >> shoe_size;
            shoe_sizes[i].name = name;
            shoe_sizes[i].shoe_size = stof(shoe_size);

            if (i == 0)
            {
                root = tree.Insert(root, shoe_sizes[i].name, shoe_sizes[i].shoe_size);
            }
            else
            {
                tree.Insert(root, shoe_sizes[i].name, shoe_sizes[i].shoe_size);
            }
        }

        tree.Inorder(root);

        root = tree.removeDuplicates(root);

        cout << endl
             << "After Removing Duplicates: " << endl;
        tree.Inorder(root);
        cout << endl;

        // Delete the binary tree
        // tree.deleteTree(root);

        in.close(); // close the input stream

        return 0;
    }