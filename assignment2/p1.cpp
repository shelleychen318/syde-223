#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <stack>
#include <vector>

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
    vector<float> repeatedValues;

    // Default constructor.
    StudentNode();
    StudentNode(string name, float shoe_size) : name(name), shoe_size(shoe_size), leftChild(nullptr), rightChild(nullptr) {}
    StudentNode *Insert(StudentNode *, string, float);       // Insert function
    StudentNode *Delete(StudentNode *root, float shoe_size); // Delete function

    void Inorder(StudentNode *root);
    void traverseAndPrintNames(StudentNode *node, float &prevNumber);
    void printNamesWithSameNumber(StudentNode *root);
    StudentNode *deleteWithSameNumber(StudentNode *&root, float deletevalue);
};

StudentNode::StudentNode() : name(""), shoe_size(0), leftChild(nullptr), rightChild(nullptr) {}

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
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process right nodes.
        root->rightChild = Insert(root->rightChild, name, shoe_size);
    }
    else if (shoe_size < root->shoe_size)
    {
        // Insert left node data, if the 'value'
        // to be inserted is smaller than 'root' node data.

        // Process left nodes.
        root->leftChild = Insert(root->leftChild, name, shoe_size);
    }

    // Return 'root' node, after insertion.
    return root;
}

void StudentNode::traverseAndPrintNames(StudentNode *node, float &prevNumber)
{
    if (node)
    {
        traverseAndPrintNames(node->leftChild, prevNumber);

        if (node->shoe_size != prevNumber)
        {
            if (node->name != "" && node->rightChild != nullptr)
            {
                cout << endl
                     << node->shoe_size << ": " << node->name << ", ";
                repeatedValues.push_back(node->shoe_size);
                repeatedValues.push_back(node->shoe_size);
            }
            prevNumber = node->shoe_size;
        }
        else
        {
            if (node->name != "")
            {
                cout << node->name << ", ";
            }
        }

        traverseAndPrintNames(node->rightChild, prevNumber);
    }
}

void StudentNode::Inorder(StudentNode *root)
{
    if (!root)
    {
        return;
    }
    Inorder(root->leftChild);
    cout << root->shoe_size << " " << root->name << endl;
    Inorder(root->rightChild);
}

void StudentNode::printNamesWithSameNumber(StudentNode *root)
{
    float prevNumber = -1;                   // Initialize the previous number as -1
    traverseAndPrintNames(root, prevNumber); // Start the traversal and printing process
    cout << endl;
}

StudentNode *StudentNode::deleteWithSameNumber(StudentNode *&root, float deletevalue)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    root->leftChild = deleteWithSameNumber(root->leftChild, deletevalue);
    root->rightChild = deleteWithSameNumber(root->rightChild, deletevalue);

    if (root->shoe_size == deletevalue)
    {
        if (root->leftChild == nullptr)
        {
            StudentNode *temp = root->rightChild;
            delete root;
            return temp;
        }
        else if (root->rightChild == nullptr)
        {
            StudentNode *temp = root->leftChild;
            delete root;
            return temp;
        }
        else
        {
            StudentNode *minValueNode = root->rightChild;
            while (minValueNode->leftChild != nullptr)
            {
                minValueNode = minValueNode->leftChild;
            }
            root->shoe_size = minValueNode->shoe_size;
            root->name = minValueNode->name;
            root->rightChild = deleteWithSameNumber(root->rightChild, minValueNode->shoe_size);
        }
    }

    return root;
}

int main()
{
    StudentNode tree, *root = nullptr;

    in.open("shoe_sizes.txt"); // opening up the shoe size text file

    if (in.fail()) // if the file fails to open
    {
        cout << "Input file opening failed\n";
        exit(1);
    }

    Student shoe_sizes[20];
    string name;
    string shoe_size;

    for (int i = 0; i < 20; i++)
    {
        in >> name >> shoe_size;
        shoe_sizes[i].name = name; // storing data into an array
        shoe_sizes[i].shoe_size = stof(shoe_size);

        if (i == 0)
        {
            root = tree.Insert(root, shoe_sizes[i].name, shoe_sizes[i].shoe_size); // making a BST from array, creating the first root
        }
        else
        {
            tree.Insert(root, shoe_sizes[i].name, shoe_sizes[i].shoe_size); // making a BST from array
        }
    }

    cout << "Original tree:" << endl;
    tree.Inorder(root);

    cout << endl
         << "Duplicate shoe sizes:";
    tree.printNamesWithSameNumber(root);

    for (int i = 0; i < tree.repeatedValues.size(); i++)
    {
        root = tree.deleteWithSameNumber(root, tree.repeatedValues[i]);
    }

    cout << endl
         << "Tree with duplicates removed:" << endl;
    tree.Inorder(root);
}