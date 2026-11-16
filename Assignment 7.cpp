// Assignment 7: Generic Stack and Queue using templates
#include <iostream>
#include <string>
using namespace std;

// Generic Stack
template <class T>
class Stack {
private:
    T arr[5];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(T value) {
        if (top == 4) {
            cout << "Stack is Full!" << endl;
        } else {
            arr[++top] = value;
            cout << "Inserted: " << value << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is Empty!" << endl;
        } else {
            cout << "Deleted: " << arr[top] << endl;
            top--;
        }
    }

    void display() const {
        if (top == -1) {
            cout << "Stack is Empty!" << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

// Generic Queue
template <class T>
class Queue {
private:
    T arr[5];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    void enqueue(T value) {
        if (rear == 4) {
            cout << "Queue is Full!" << endl;
        } else {
            arr[++rear] = value;
            cout << "Inserted: " << value << endl;
        }
    }

    void dequeue() {
        if (front > rear) {
            cout << "Queue is Empty!" << endl;
        } else {
            cout << "Deleted: " << arr[front] << endl;
            front++;
        }
    }

    void display() const {
        if (front > rear) {
            cout << "Queue is Empty!" << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "--- Integer Stack ---" << endl;
    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.display();
    s1.pop();
    s1.display();

    cout << "\n--- Float Queue ---" << endl;
    Queue<float> q1;
    q1.enqueue(10.5);
    q1.enqueue(20.5);
    q1.display();
    q1.dequeue();
    q1.display();

    cout << "\n--- String Stack ---" << endl;
    Stack<string> s2;
    s2.push("Hello");
    s2.push("C++");
    s2.display();

    cout << "\n--- String Queue ---" << endl;
    Queue<string> q2;
    q2.enqueue("First");
    q2.enqueue("Second");
    q2.display();

    return 0;
}
