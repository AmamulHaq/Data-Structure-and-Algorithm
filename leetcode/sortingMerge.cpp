#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

Node* split(Node* head) {
    if (!head || !head->next) return nullptr;
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    Node* second = slow->next;
    slow->next = nullptr;
    if (second) second->prev = nullptr;
    
    return second;
}

Node* merge(Node* first, Node* second) {
    if (!first) return second;
    if (!second) return first;

    if (first->data < second->data) {
        first->next = merge(first->next, second);
        if (first->next) first->next->prev = first;
        first->prev = nullptr;
        return first;
    } else {
        second->next = merge(first, second->next);
        if (second->next) second->next->prev = second;
        second->prev = nullptr;
        return second;
    }
}
Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;
    
    Node* second = split(head);
    
    head = mergeSort(head);
    second = mergeSort(second);
    
    return merge(head, second);
}

void append(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n, val;
    
    cout << "Enter number of elements: ";
    cin >> n;
    
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        append(head, val);
    }
    
    head = mergeSort(head);
    
    cout << "Sorted List: ";
    printList(head);
    
    return 0;
}
