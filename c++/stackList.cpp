#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
    list<int> stack;

public:
    void isEmpty() {
        if (stack.empty()) {
            cout << "Stack is Empty." << endl;
        } else {
            cout << "Stack is NOT Empty and Current size: " << stack.size() << endl;
        }
    }

    void isFull() {
        cout << "Stack is dynamic, so it's never 'full' in a traditional sense." << endl;
        cout << "Current size: " << stack.size() << endl;
    }

    void size() {
        cout << "Current Stack Size: " << stack.size() << endl;
    }

    void push(int t) {
        stack.push_back(t);
        cout << "Pushed: " << t << endl;
    }

    void pop() {
        if (stack.empty()) {
            cout << "Stack is already empty!" << endl;
        } else {
            cout << "Popped: " << stack.back() << endl;
            stack.pop_back();
        }
    }

    void display() {
        if (stack.empty()) {
            cout << "Stack is Empty." << endl;
            return;
        }
        cout << "Stack Elements: ";
        for (auto it = stack.rbegin(); it != stack.rend(); ++it) {
            cout << *it << " ";
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
