#include <iostream>
using namespace std;
int SIZE;
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
    cout<<"Enter no of nodes: "<<endl;
    cin>>SIZE;
    char tree[SIZE];
    cout<<"Enter sequence of nodes: "<<endl;
    for(int i=0; i<SIZE; i++){
    cin>>tree[i];
    }
    printTree(tree);
    return 0;
}
