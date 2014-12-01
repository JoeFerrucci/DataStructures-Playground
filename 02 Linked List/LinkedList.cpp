#include <iostream>
using namespace std;

template <typename Object>
class LinkedList {
public:

    struct Node {
        Object data;
        Node *next;
        Node *prev;
        Node(const Object &d = Object(), Node *n = NULL, Node *p = NULL) : data(d), next(n), prev(p) {}
    };

    LinkedList() : head(NULL), tail(NULL), theSize(0) { 
        head = new Node;
        tail = new Node;
    }

    void insert(const Object &obj) {
        Node *newNode = new Node(obj);
        Node *temp = head->next;
        head->next = newNode;
    }

    void print() {
        Node *temp = head->next;
        while (temp->next != NULL) {
            cout << temp->data << "\n";
            temp = temp->next;
        }
    }

private:
    Node *head;
    Node *tail;
    int theSize;
};


int main() {
    LinkedList<int> list;
    
    list.insert(3);
    list.insert(5);
    list.insert(7);
    list.insert(9);
    list.insert(12);
    list.insert(15);
    list.print();

    return 0;
}

