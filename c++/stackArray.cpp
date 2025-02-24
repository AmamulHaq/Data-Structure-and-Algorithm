#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 3;

class Stack {
private:
    int stack[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void isEmpty() {
      if (top == -1) {
         cout << "Stack is Empty." << endl;
        } else {
            cout << "Stack is NOT Empty and Current size: " << top + 1 << endl;
        }
    }

    void isFull() {
        if (top == MAX_SIZE - 1) {
            cout << "Stack is FULL." << endl;
        } else {
            cout << "Stack is NOT Full and Current size: " << top + 1 << endl;
        }
    }

    void size() {
        cout << "Current Stack Size: " << (top + 1) << endl;
    }

    void push(int t) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack is FULL. Cannot push " << t << endl;
        } else {
            stack[++top] = t;
            cout << "Pushed: " << t << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is already empty!" << endl;
        } else {
            cout << "Popped: " << stack[top--] << endl;
        }
    }

    void display() {
        if (top == -1) {
            cout << "Stack is Empty." << endl;
            return;
        }
        cout << "Stack Elements: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.isEmpty();
    s.isFull();

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40); 

    s.isFull();
    s.isEmpty();
    s.display();

    s.pop();
    s.pop();
    s.pop();
    s.pop();

    s.isEmpty();

    return 0;
}
