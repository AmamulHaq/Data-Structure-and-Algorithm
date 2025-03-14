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

void search(int tree[], int value){
    for (int i = 0; i < MAX_SIZE; i++) {
        if (tree[i] == value) {
            cout << "Node: " << tree[i] << " Found at: " << i << endl;
            return;
        }
    }
    cout << "Node: " << value << " does not exist!." << endl;
}

void deleteBST(int tree[], int value) {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (tree[i] == value) {
            int LC = 2 * i + 1;
            int RC = 2 * i + 2;
            
            if ((LC >= MAX_SIZE || tree[LC] == -1) && 
                (RC >= MAX_SIZE || tree[RC] == -1)) {
                tree[i] = -1;
                return;
            } else if (LC < MAX_SIZE && tree[LC] != -1) {
                tree[i] = tree[LC];
                tree[LC] = -1;
                return;
            } else if (RC < MAX_SIZE && tree[RC] != -1) {
                tree[i] = tree[RC];
                tree[RC] = -1;
                return;
            }
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

    cout << "Enter node to insert: ";
    cin >> value;
    insertBST(tree, value);
    printTree(tree);
    
    cout << "Enter node to search: ";
    cin >> value;
    search(tree, value);

    cout << "Enter node to delete: ";
    cin >> value;
    deleteBST(tree, value);
    printTree(tree);
    
    return 0;
}
