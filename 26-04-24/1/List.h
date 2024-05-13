#ifndef STUDY_LIST_H
#define STUDY_LIST_H


#include <iostream>
using namespace std;

class List {
public:
    virtual void insert(int value) = 0;
    virtual void remove() = 0;
    virtual void display() = 0;
};

class Stack : public List {
private:
    int stack[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void insert(int value) override {
        if (top >= 99) {
            cout << "Stack overflow!\n";
            return;
        }
        stack[++top] = value;
    }

    void remove() override {
        if (top < 0) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Popped value: " << stack[top--] << endl;
    }

    void display() override {
        if (top < 0) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Stack: ";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << endl;
    }
};

class Queue : public List {
private:
    int queue[100];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    void insert(int value) override {
        if (rear >= 99) {
            cout << "Queue overflow!\n";
            return;
        }
        if (front == -1)
            front = 0;
        queue[++rear] = value;
    }

    void remove() override {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Removed value: " << queue[front++] << endl;
        if (front > rear)
            front = rear = -1;
    }

    void display() override {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    }
};




#endif //STUDY_LIST_H
