#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* parent;
    Node* next;  
    Node* prev;  

    Node(char value) : data(value), parent(nullptr), next(nullptr), prev(nullptr) {}
};

void printTree(Node* tree[], int size) {
    cout << "| Index | Node | Parent |\n";
    cout << "-------------------------\n";

    for (int i = 0; i < size; i++) {
        char parentChar = '-';
        
        if (tree[i]->parent) {
            parentChar = tree[i]->parent->data;
        }

        cout << "| " << i << "     | " << tree[i]->data << "    | " << parentChar << "      |\n";
    }
}

int main() {
    int SIZE;
    cout << "Enter no of nodes: " << endl;
    cin >> SIZE;

    Node* tree[SIZE];

    cout << "Enter sequence of nodes: " << endl;
    for (int i = 0; i < SIZE; i++) {
        char value;
        cin >> value;
        tree[i] = new Node(value);
    }

    for (int i = 1; i < SIZE; i++) {
        int parentIndex = (i - 1) / 2;
        tree[i]->parent = tree[parentIndex];
    }

    printTree(tree, SIZE);

    for (int i = 0; i < SIZE; i++) {
        delete tree[i];
    }
    return 0;
}
