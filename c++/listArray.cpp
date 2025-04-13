#include <iostream>
using namespace std;

const int SIZE = 10;

class List {
    int list[SIZE];
    int head, tail;

public:
    List() : head(-1), tail(-1) {}

    bool isFull() const {
        return tail == SIZE - 1;
    }

    bool isEmpty() const {
        return head == -1;
    }

    void insert_begin(int item) {
        if (isFull()) {
            cout << "List is full!\n";
            return;
        }
        if (isEmpty()) {
            head = tail = 0;
        } else {
            for (int i = tail; i >= head; --i)
                list[i + 1] = list[i];
            ++tail;
        }
        list[head] = item;
    }

    void insert_end(int item) {
        if (isFull()) {
            cout << "List is full!\n";
            return;
        }
        if (isEmpty())
            head = tail = 0;
        else
            ++tail;
        list[tail] = item;
    }

    void insert_pos(int item, int pos) {
        if (isFull()) {
            cout << "List is full!\n";
            return;
        }
        if (pos < 0 || pos > length()) {
            cout << "Invalid position!\n";
            return;
        }
        for (int i = tail; i >= head + pos; --i)
            list[i + 1] = list[i];
        ++tail;
        list[head + pos] = item;
    }

    int delete_begin() {
        if (isEmpty()) {
            cout << "List is empty!\n";
            return -1;
        }
        int item = list[head];
        if (head == tail)
            head = tail = -1;
        else
            ++head;
        return item;
    }

    int delete_end() {
        if (isEmpty()) {
            cout << "List is empty!\n";
            return -1;
        }
        int item = list[tail];
        if (head == tail)
            head = tail = -1;
        else
            --tail;
        return item;
    }

    int delete_pos(int pos) {
        if (isEmpty()) {
            cout << "List is empty!\n";
            return -1;
        }
        if (pos < 0 || pos >= length()) {
            cout << "Invalid position!\n";
            return -1;
        }
        int item = list[head + pos];
        for (int i = head + pos; i < tail; ++i)
            list[i] = list[i + 1];
        --tail;
        if (head > tail)
            head = tail = -1;
        return item;
    }

    int delete_item(int item) {
        if (isEmpty()) {
            cout << "List is empty!\n";
            return -1;
        }
        for (int i = head; i <= tail; ++i) {
            if (list[i] == item) {
                for (int j = i; j < tail; ++j)
                    list[j] = list[j + 1];
                --tail;
                if (head > tail)
                    head = tail = -1;
                return item;
            }
        }
        cout << "Item not found!\n";
        return -1;
    }

    int length() const {
        return isEmpty() ? 0 : tail - head + 1;
    }

    void display() const {
        if (isEmpty()) {
            cout << "List is empty!\n";
            return;
        }
        for (int i = head; i <= tail; ++i)
            cout << list[i] << " ";
        cout << endl;
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
}