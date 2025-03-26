#include <iostream>
using namespace std;

const int MAX_SIZE = 15;

void insertBST(int tree[], int value) {
    int index = 0;
    while (index < MAX_SIZE) {
        if (tree[index] == -1) {  
            tree[index] = value;
            return;
        } else if (value < tree[index]) {
            index = 2 * index + 1;
        } else if (value > tree[index]) {
            index = 2 * index + 2;
        } else {
            return;
        }
    }
}

void printTree(const int tree[]) {
    cout << "| Index | Node | Parent |\n";
    cout << "-------------------------\n";
    for (int i = 0; i < MAX_SIZE; i++) {
        int parent = -1; 
        if (i > 0) {
            int parentIndex = (i - 1) / 2;
            parent = tree[parentIndex];
        }
        if (tree[i] == -1) {
            cout << "| " << i << "     |  _   |   _   |\n";
        } else {
            cout << "| " << i << "     | " << tree[i] << "    | " << parent << "      |\n";
        }
    }
}

int main() {
    int SIZE;
    cout << "Enter number of nodes: ";
    cin >> SIZE;
    int tree[MAX_SIZE];
    int value;
    
    for (int i = 0; i < MAX_SIZE; i++) tree[i] = -1;
    
    cout << "Enter sequence of nodes: " << endl;
    for (int i = 0; i < SIZE; i++) {
        cin >> value;
        insertBST(tree, value);
    }
    
    printTree(tree);
    
    return 0;
}
