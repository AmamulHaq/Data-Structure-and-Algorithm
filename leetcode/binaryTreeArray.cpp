#include <iostream>
using namespace std;

#define SIZE 15

void printTree(char tree[]) {
    cout << "| Index | Node | Parent |\n";
    cout << "-------------------------\n";

    for (int i = 0; i < SIZE; i++) {
        char parent = '-';

        if (i > 0) {
            int parentIndex = (i - 1) / 2;
            parent = tree[parentIndex];
        }

        cout << "| " << i << "     | " << tree[i] << "    | " << parent << "      |\n";
    }
}

int main() {
    char tree[SIZE] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', '-', '-', 'H', 'I', 'J', 'K', '-', '-'};
    printTree(tree);
    return 0;
}
