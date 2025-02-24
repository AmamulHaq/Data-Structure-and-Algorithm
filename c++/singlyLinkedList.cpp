#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << "Data: " << temp->data;
        if (temp->next != NULL) {
            cout << " | -> " << temp->next->data << endl;
        } else {
            cout << " | -> NULL" << endl;
        }
        temp = temp->next;
    }
    cout << endl;
}

void InsertAtFirst(Node* &head, int d) {
    Node* newNode = new Node(d);
    newNode->next = head;
    head = newNode;
}

void InsertAtLast(Node* &head, int d) {
    Node* last = new Node(d);
    if (head == NULL) {
        head = last;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = last;
}

void InsertAfter(Node* &head, int after, int value) {
    Node* temp = head;
    while (temp != NULL && temp->data != after) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Node with value " << after << " not found!" << endl;
        return;
    }
    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtFirst(Node* &head) {
    if (head == NULL) {
        cout << "List is already empty!" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteAtLast(Node* &head) {
    if (head == NULL) {
        cout << "List is already empty!" << endl;
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void deleteFromTo(Node* &head, int From, int To) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->data != From) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Node with value " << From << " not found!" << endl;
        return;
    }

    Node* current = temp;
    while (current != NULL && current->data != To) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    if (prev != NULL) {
        prev->next = current;
    } else {
        head = current;
    }
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(30);
    head->next->next = new Node(40);

    display(head);

    InsertAtFirst(head, 12);
    display(head);

    InsertAtLast(head, 43);
    display(head);

    InsertAfter(head, 30, 786);
    display(head);

    deleteFromTo(head, 10, 40);
    display(head);

    deleteAtFirst(head);
    display(head);

    deleteAtLast(head);
    display(head);

    return 0;
}
