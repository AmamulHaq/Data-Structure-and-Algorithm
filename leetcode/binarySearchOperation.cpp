#include <iostream>
#include <map>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
    Node(int value) : data(value), left(nullptr), right(nullptr), parent(nullptr) {}
};

class BST {
public:
    Node* root;
    map<Node*, int> indexMap;

    BST() : root(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (!root) {
            root = newNode;
            indexMap[newNode] = 0;
            return;
        }
        Node* current = root;
        Node* parent = nullptr;
        int index = 0;
        while (current) {
            parent = current;
            if (value < current->data) {
                if (!current->left) {
                    index = 2 * indexMap[parent] + 1;
                    break;
                }
                current = current->left;
            } else if (value > current->data) {
                if (!current->right) {
                    index = 2 * indexMap[parent] + 2;
                    break;
                }
                current = current->right;
            } else {
                return;
            }
        }
        newNode->parent = parent;
        indexMap[newNode] = index;
        if (value < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
    }

    void updateIndexes(Node* node, int index) {
        if (!node) return;
        indexMap[node] = index;
        updateIndexes(node->left, 2 * index + 1);
        updateIndexes(node->right, 2 * index + 2);
    }

    void printTree() {
        cout << "| Index | Node | Parent |\n";
        cout << "-------------------------\n";
        for (int i = 0; i < 15; i++) {
            bool found = false;
            for (auto it : indexMap) {
                if (it.second == i) {
                    int parent = it.first->parent ? it.first->parent->data : -1;
                    cout << "| " << i << "     | " << it.first->data << "    | " << parent << "      |\n";
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "| " << i << "     |  _   |   _   |\n";
        }
    }

    void insertNode(int value) {
        insert(value);
        updateIndexes(root, 0);
        cout << "Inserted node " << value << " successfully.\n";
    }

    Node* findMin(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    Node* search(Node* node, int value) {
        if (!node || node->data == value) return node;
        if (value < node->data) return search(node->left, value);
        return search(node->right, value);
    }

    void deleteNode(int value) {
        Node* nodeToDelete = search(root, value);
        if (!nodeToDelete) {
            cout << "Node " << value << " not found.\n";
            return;
        }
        Node* parent = nodeToDelete->parent;

        if (!nodeToDelete->left && !nodeToDelete->right) {
            if (!parent) root = nullptr;
            else if (parent->left == nodeToDelete) parent->left = nullptr;
            else parent->right = nullptr;
            indexMap.erase(nodeToDelete);
            delete nodeToDelete;
        } else if (!nodeToDelete->left || !nodeToDelete->right) {
            Node* child = nodeToDelete->left ? nodeToDelete->left : nodeToDelete->right;
            if (!parent) root = child;
            else if (parent->left == nodeToDelete) parent->left = child;
            else parent->right = child;
            child->parent = parent;
            indexMap.erase(nodeToDelete);
            delete nodeToDelete;
        } else {
            Node* successor = findMin(nodeToDelete->right);
            nodeToDelete->data = successor->data;
            deleteNode(successor->data);
            return;
        }

        updateIndexes(root, 0);
        cout << "Deleted node " << value << " successfully.\n";
    }
};

int main() {
    int SIZE;
    cout << "Enter number of nodes: ";
    cin >> SIZE;
    BST tree;
    cout << "Enter sequence of nodes: " << endl;
    for (int i = 0; i < SIZE; i++) {
        int value;
        cin >> value;
        tree.insert(value);
    }

    tree.printTree();

    int insertVal, deleteVal;
    cout << "Enter a node to insert: ";
    cin >> insertVal;
    tree.insertNode(insertVal);
    tree.printTree();

    cout << "Enter a node to delete: ";
    cin >> deleteVal;
    tree.deleteNode(deleteVal);
    tree.printTree();

    return 0;
}
