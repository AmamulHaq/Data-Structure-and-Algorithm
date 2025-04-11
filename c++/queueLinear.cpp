#include <iostream>
using namespace std;

const int MAX_SIZE = 3;

class Queue {
private:
    char arr[MAX_SIZE]; 
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    void enqueue(char item) {
        if (rear == MAX_SIZE - 1) {
            cout << "Queue is full! Cannot enqueue: " << item << endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = item;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }
        cout << "Deleted: " << arr[front] << endl;
        arr[front]=NULL;// limitation
        front++;
        // solution
        for (int i = front; i < rear; i++) {
            arr[i] = arr[i + 1];
        }
        rear--;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements are: ";
        for (int i = 0; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue('t');
    q.enqueue('w');
    q.enqueue('0');
    q.enqueue('3');
    q.display(); 
    q.dequeue();
    q.display(); 
    q.enqueue('3'); 
    q.display(); 
    
    return 0;
}