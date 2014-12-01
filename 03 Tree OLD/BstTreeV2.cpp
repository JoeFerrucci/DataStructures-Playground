#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
};

class Tree {
public:
    Tree() {
        rootPtr = NULL;    // empty tree
    }
    void Insert(int data) {
        InsertNode(rootPtr, data);
    }
    void InsertNode(Node *root, int data) {
        if (root == NULL) {
            Node *newNode = new Node();
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
        }
        else if (root->data < data) {
            InsertNode(root->left, data);
        }
        else {
            InsertNode(root->right, data);
        }
    }
    void Traverse() {
        TraverseTree(rootPtr);
    }
    void TraverseTree(Node *root) {
        if (root != NULL) {
            TraverseTree(root->left);
            ProcessNode(root->data);
            TraverseTree(root->right);
        }
    }
    void ProcessNode(int data)
    {
        printf("Node(=%d)\n", data);
    }
private:
    Node *rootPtr;
};


int main(int argc, char *argv[])
{
    Tree tree;
    tree.Insert(13);
    tree.Insert(15);
    tree.Insert(12);

    tree.Traverse();

}