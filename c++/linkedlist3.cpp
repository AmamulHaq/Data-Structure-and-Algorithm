#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void display(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << "Data: " << temp->data << " ";
        cout << "Next: " << temp->next << " ";
        cout << "Prev: " << temp->prev << endl;
        temp = temp->next;
    }
    cout << endl;
}

void InsertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    if (head != NULL) {
        head->prev = temp;
    }
    head = temp;
}

void InsertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void deleteAtHead(Node* &head) {
    if (head == NULL) return;
    
    Node* temp = head;
    head = head->next;
    
    if (head != NULL) {
        head->prev = NULL;
    }

    delete temp;
}

void deleteAtTail(Node* &head, Node* &tail) {
    if (head == NULL) return;
    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }
    Node* temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete temp;
}

int main() {
    Node* link1 = new Node(10);
    Node* head = link1;
    Node* tail = link1;

    Node* link2 = new Node(20);
    link1->next = link2;
    link2->prev = link1;
    tail = link2;

    Node* link3 = new Node(30);
    link2->next = link3;
    link3->prev = link2;
    tail = link3;

    display(head);
    
    InsertAtHead(head, 24);
    InsertAtTail(tail, 43);
    display(head);

    deleteAtHead(head);
    display(head);

    deleteAtTail(head, tail);
    display(head);

    return 0;
}
