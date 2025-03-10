#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* parent;
    Node* next;  // Next pointer for the child node
    Node* prev;  // Previous pointer for the parent node

    Node(char value) : data(value), parent(nullptr), next(nullptr), prev(nullptr) {}  // Constructor to initialize node
};

void printTree(Node* tree[], int size) {
    cout << "| Index | Node | Parent Index | Parent Node |\n";
    cout << "-------------------------------------------\n";

    for (int i = 0; i < size; i++) {
        int parentIndex = -1;
        char parentChar = '-';
        
        if (i > 0) {
            parentIndex = (i - 1) / 2;
            parentChar = tree[parentIndex]->data; // Access the parent node's character
        }

        cout << "| " << i << "     | " << tree[i]->data << "    | " << parentIndex << "           | " << parentChar << "       |\n";
    }
}

int main() {
    const int SIZE = 15;
    
    Node* tree[SIZE];
    tree[0] = new Node('A');
    tree[1] = new Node('B');
    tree[2] = new Node('C');
    tree[3] = new Node('D');
    tree[4] = new Node('E');
    tree[5] = new Node('F');
    tree[6] = new Node('G');
    tree[7] = new Node('H');
    tree[8] = new Node('I');
    tree[9] = new Node('J');
    tree[10] = new Node('K');
    tree[11] = new Node('L');
    tree[12] = new Node('M');
    tree[13] = new Node('N');
    tree[14] = new Node('O');
    
    // Connect the parent-child relationships using prev (parent) and next (child) pointers
    tree[1]->parent = tree[0]; // B -> A
    tree[2]->parent = tree[0]; // C -> A
    tree[3]->parent = tree[1]; // D -> B
    tree[4]->parent = tree[1]; // E -> B
    tree[5]->parent = tree[2]; // F -> C
    tree[6]->parent = tree[2]; // G -> C
    tree[7]->parent = tree[3]; // H -> D
    tree[8]->parent = tree[3]; // I -> D
    tree[9]->parent = tree[4]; // J -> E
    tree[10]->parent = tree[4]; // K -> E
    tree[11]->parent = tree[5]; // L -> F
    tree[12]->parent = tree[5]; // M -> F
    tree[13]->parent = tree[6]; // N -> G
    tree[14]->parent = tree[6]; // O -> G

    // Print tree with parent indices
    printTree(tree, SIZE);

    // Free dynamically allocated memory
    for (int i = 0; i < SIZE; i++) {
        delete tree[i];
    }

    return 0;
}
