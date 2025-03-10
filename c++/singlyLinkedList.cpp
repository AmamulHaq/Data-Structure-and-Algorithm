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
    Node* first = new Node(d);
    first->next = head;
    head = first;
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
    last->next = NULL;
}

void InsertAfter(Node* &head, int aft, int value) {
    Node* after = new Node(value);
    Node* temp = head;
    while (temp != NULL && temp->data != aft) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Node with value " << aft << " not found!" << endl;
        return;
    }
    after->next = temp->next;
    temp->next = after;
}

void deleteAtFirst(Node* &head) {
    if (head == NULL) {
        cout << "List is already empty!" << endl;
        return;
    }
    Node* first = head;
    head = head->next;
    delete first;
}

void deleteAtLast(Node* &head) {
    if (head == NULL || head->next == NULL) {
        cout << "List is already empty! or single node" << endl;
        delete head;
        head = NULL;
        return;
    }
    Node* last = head;
    while (last->next->next != NULL) {
        last = last->next;
    }
    delete last->next;
    last->next = NULL;
}

void deleteFromTo(Node* &head, int From, int To) {
    Node* temp = head;
    Node* prevNode = NULL;

    // Find the node with value 'From'
    while (temp != NULL && temp->data != From) {
        prevNode = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Node with value " << From << " not found!" << endl;
        return;
    }

    Node* startNode = temp;  // 'From' node found

    // Delete nodes from 'From' to 'To'
    while (temp != NULL && temp->data != To) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    // If 'To' node is not found, delete all nodes from 'From' onward
    if (temp == NULL) {
        cout << "Node with value " << To << " not found!" << endl;
    } else {
        // 'To' node found, delete it
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    // Adjust the head pointer or previous node's next pointer
    if (prevNode != NULL) {
        prevNode->next = temp;  // Now points to the node after the deleted nodes
    } else {
        head = temp;  // If the 'From' node was the head
    }

    // Ensure the last node's next is set to NULL if necessary
    if (temp == NULL) {
        prevNode->next = NULL;
    }

    cout << "Deleted all nodes from " << From << " to the end." << endl;
}



int main() {
    Node* head = new Node(786);
    head->next = new Node(30);
    head->next->next = new Node(40);
    display(head);

    InsertAtFirst(head, 12);
    display(head);

    InsertAtLast(head, 43);
    display(head);

    InsertAfter(head, 30, 5);
    display(head);

    deleteFromTo(head, 30, 40);
    display(head);

    deleteAtFirst(head);
    display(head);

    deleteAtLast(head);
    display(head);

    return 0;
}
