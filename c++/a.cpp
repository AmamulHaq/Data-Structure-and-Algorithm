#include <bits/stdc++.h>
using namespace std;

stack<int> s;

const int MAX_SIZE = 3;

void isEmpty() {
    if (s.empty()) {
        cout << "Stack is Empty." << endl;
    } else {
        cout << "Stack is not Empty and Current size: " << s.size() << endl;
    }
}

void isFull() {
    if (s.size() >= MAX_SIZE) {
        cout << "Stack is FULL." << endl;
    } else {
        cout << "Stack is NOT full and Current size: " << s.size() << endl;
    }
}

void Push(int t) {
    if (s.top() >= MAX_SIZE) {
        cout << "Stack is FULL. Cannot push " << t << endl;
    } else {
        s.push(t);
        cout << "Pushed: " << t << endl;
    }
}

void Pop() {
    if (s.top()==-1) {
       cout << "Stack is already empty!" << endl;
    } else {
     cout << "Popped: " << s.top() << endl;
        s.pop();
    }
}

void Display() {
    if (s.top()==-1) {
        cout << "Stack is Empty." << endl;
        return;
    }
    stack<int> temp = s;
    cout << "Stack Elements: ";
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

int main() {
    isEmpty();
    isFull();

    Push(10);
    Push(20);
    Push(30);
    Push(40); 

    isFull();
    isEmpty();
    Display();

    Pop();
    Pop();
    Pop();
    Pop();

    isEmpty();

    return 0;
}
