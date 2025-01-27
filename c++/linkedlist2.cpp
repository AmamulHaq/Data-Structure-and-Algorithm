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

void display(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << "Data: " << temp->data << " ";
        cout << "Pointing: " << temp << endl;
        temp = temp->next;
    }
    cout << endl;
}

void InsertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void deleteFromTo(Node* &head, int a, int b) {
    Node* from = head;
    Node* prev = NULL;

    for (int i = 1; from != NULL && i < a; i++) {
        prev = from;
        from = from->next;
    }

    for (int i = a; from != NULL && i <= b; i++) {
        Node* next = from->next;
        delete from;
        from = next;
    }

    if (prev != NULL) {
        prev->next = from;
    } else {
        head = from;
    }
}
void InsertAt(Node* &head, int a, int value) {
    Node* from = head;
    Node* prev = NULL;

    for (int i = 1; from != NULL && i < a; i++) {
        prev = from;
        from = from->next;
    }
    
    Node* newNode = new Node(value);
    if (prev != NULL) {
        prev->next = newNode;
    } else {
        head = newNode;
    }
    newNode->next = from;
}


int main() {
    Node* link1 = new Node(10);
    Node* head = link1;
    Node* tail = link1;

    Node* link2 = new Node(30);
    link1->next = link2;
    tail = link2;

    Node* link3 = new Node(40);
    link2->next = link3;
    tail = link3;

    InsertAtHead(head, 12);
    display(head);

    InsertAtTail(tail, 43);
    display(head);

    deleteFromTo(head, 2, 3);
    display(head);

    InsertAt(head,2,786);
    display(head);
    return 0;
}
