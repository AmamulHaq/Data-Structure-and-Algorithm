#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class List {
    Node* head;

public:
    List() : head(nullptr) {}

    void insert_begin(int item) {
        Node* newNode = new Node(item);
        newNode->next = head;
        head = newNode;
    }

    void insert_end(int item) {
        Node* newNode = new Node(item);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void insert_pos(int item, int pos) {
        if (pos < 0) {
            cout << "Invalid position!\n";
            return;
        }
        if (pos == 0) {
            insert_begin(item);
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp; i++)
            temp = temp->next;
        if (!temp) {
            cout << "Position out of range!\n";
            return;
        }
        Node* newNode = new Node(item);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int delete_begin() {
        if (!head) {
            cout << "List is empty!\n";
            return -1;
        }
        Node* temp = head;
        int val = temp->data;
        head = head->next;
        delete temp;
        return val;
    }

    int delete_end() {
        if (!head) {
            cout << "List is empty!\n";
            return -1;
        }
        if (!head->next) {
            int val = head->data;
            delete head;
            head = nullptr;
            return val;
        }
        Node* temp = head;
        while (temp->next->next)
            temp = temp->next;
        int val = temp->next->data;
        delete temp->next;
        temp->next = nullptr;
        return val;
    }

    int delete_pos(int pos) {
        if (!head) {
            cout << "List is empty!\n";
            return -1;
        }
        if (pos == 0)
            return delete_begin();
        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp->next; i++)
            temp = temp->next;
        if (!temp->next) {
            cout << "Position out of range!\n";
            return -1;
        }
        Node* toDelete = temp->next;
        int val = toDelete->data;
        temp->next = toDelete->next;
        delete toDelete;
        return val;
    }

    int delete_item(int item) {
        if (!head) {
            cout << "List is empty!\n";
            return -1;
        }
        if (head->data == item)
            return delete_begin();
        Node* temp = head;
        while (temp->next && temp->next->data != item)
            temp = temp->next;
        if (!temp->next) {
            cout << "Item not found!\n";
            return -1;
        }
        Node* toDelete = temp->next;
        int val = toDelete->data;
        temp->next = toDelete->next;
        delete toDelete;
        return val;
    }

    int length() const {
        int count = 0;
        Node* temp = head;
        while (temp) {
            temp = temp->next;
            count++;
        }
        return count;
    }

    void display() const {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~List() {
        while (head)
            delete_begin();
    }
};

int main() {
    List l;
    
    l.insert_end(10);
    l.insert_end(20);
    l.insert_begin(5);
    l.insert_pos(15, 2);
    
    l.display();  
    
    cout << "Deleted: " << l.delete_begin() << endl;
    cout << "Deleted: " << l.delete_pos(1) << endl;
    
    l.display();  
    
    return 0;

    return 0;
}
