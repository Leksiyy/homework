#ifndef STUDY_LINKEDLIST_H
#define STUDY_LINKEDLIST_H

#include <iostream>
using namespace std;

// Створіть шаблонний клас однозв’язного списку для роботи з цілими значеннями.
// Потрібно створити реалізації для типових операцій над елементами:
// ■ AddToHead — додавання елемента до голови списку;
// ■ AddToTail — додавання елемента до хвоста списку;
// ■ DeleteFromHead—видалення елемента з голови списку;
// ■ DeleteFromTail—видалення елемента з хвоста списку;
// ■ DeleteAll — видалення всіх елементів;
// ■ Show — виведення всіх елементів списку на екран.


template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void addToHead(const T& value) {
        Node* newNode = new Node(value);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void addToTail(const T& value) {
        Node* newNode = new Node(value);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void deleteFromHead() {
        if (!head) return;

        Node* temp = head;
        head = head->next;
        delete temp;
        size--;

        if (!head) tail = nullptr;
    }

    void deleteFromTail() {
        if (!tail) return;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            size = 0;
            return;
        }

        Node* temp = head;
        while (temp->next != tail)
            temp = temp->next;

        delete tail;
        tail = temp;
        tail->next = nullptr;
        size--;
    }

    void deleteAll() {
        while (head)
            deleteFromHead();
    }

    void show() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insertAtPosition(const T& value, int position) {
        if (position < 0 || position > size) return;

        if (position == 0)
            addToHead(value);
        else if (position == size)
            addToTail(value);
        else {
            Node* newNode = new Node(value);
            Node* temp = head;
            for (int i = 0; i < position - 1; ++i)
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
            size++;
        }
    }

    void deleteAtPosition(int position) {
        if (position < 0 || position >= size) return;

        if (position == 0)
            deleteFromHead();
        else if (position == size - 1)
            deleteFromTail();
        else {
            Node* temp = head;
            for (int i = 0; i < position - 1; ++i)
                temp = temp->next;
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            size--;
        }
    }

    int search(const T& value) const {
        Node* temp = head;
        int position = 0;
        while (temp) {
            if (temp->data == value)
                return position;
            temp = temp->next;
            position++;
        }
        return -1;
    }

    int replace(const T& oldValue, const T& newValue) {
        int count = 0;
        Node* temp = head;
        while (temp) {
            if (temp->data == oldValue) {
                temp->data = newValue;
                count++;
            }
            temp = temp->next;
        }
        return count;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        tail = head;
        head = prev;
    }

    ~LinkedList() {
        deleteAll();
    }
};


#endif //STUDY_LINKEDLIST_H
