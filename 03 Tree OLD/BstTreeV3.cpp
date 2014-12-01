#include <iostream>
using namespace std;

class Node {
    private:
        int data;
        Node* left;
        Node* right;

    public:

        Node() :data(0), left(NULL), right(NULL) {}

        Node(int d) :data(d), left(NULL), right(NULL) {}

        int GetData() const { return data; }

        Node* Left() const { return left; }
        Node* Right() const { return right; }

};

Node* GetNewNode(int data) {
    return new Node(data);;
}

void Insert(Node** root, int data) 
{
    if (*root == NULL) { // empty tree
        *root = GetNewNode(data);
    }
    else if ((*root)->GetData() < data) {
        Insert( &( (*root)->Left() ), data);
    }
    else {
        Insert( &( (*root)->Right() ), data);
    }
}

void ProcessNode(int data)
{
    cout << "Node=(" << data << ")\n";
}

void Traverse(Node* root) {
    if (root != NULL) {
        Traverse(root->Left());
        ProcessNode(root->GetData());
        Traverse(root->Right());
    }
}

int main(int argc, char *argv[])
{
    Node *treeRoot = new Node();

    Insert(&treeRoot, 15);
    Insert(&treeRoot, 23);
    Insert(&treeRoot, 10);

    // Traverse(treeRoot);

}