#include <iostream>
using namespace std;

const int MAX_SIZE = 15;

void insertBST(char tree[], char value) {
    int index = 0;
    while (index < MAX_SIZE) {
        if (tree[index] == '-') {
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

void printTree(const char tree[]) {
    cout << "| Index | Node | Parent |\n";
    cout << "-------------------------\n";
    for (int i = 0; i < MAX_SIZE; i++) {
        char parent = '-';
        if (i > 0) {
            int parentIndex = (i - 1) / 2;
            parent = tree[parentIndex];
        }
        if (tree[i] == '-') {
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
    char tree[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) tree[i] = '-';
    cout << "Enter sequence of nodes: " << endl;
    for (int i = 0; i < SIZE; i++) {
        char value;
        cin >> value;
        insertBST(tree, value);
    }
    printTree(tree);
    return 0;
}
