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

template<typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(const T& value) : data(value), next(nullptr) {};
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    ~LinkedList() {deleteAll();}

    void addToHead(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void addToTail(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (tail == nullptr) {
            tail = newNode;
        } else {
            newNode->next = tail;
            tail = newNode;
        }
    }

    void deleteFromHead() {
        if (head != nullptr) {
            Node<T>* temp = head; // взял указатель
            head = head->next;
            delete temp; // по указателю очистил память
        } else {
            cout << "Список уже/еще пуст!!!" << endl;
        }
    }

    void deleteFromTail() {
        if (tail != nullptr) {
            Node<T>* temp = tail;
            tail = tail->next;
            delete temp;
        } else {
            cout << "Список уже/еще пуст!!!" << endl;
        }
    }

    void deleteAll() {
        while (head != nullptr) {
            deleteFromHead();
        }
        while (tail != nullptr) {
            deleteFromTail();
        }
    }

    void Show() {
        Node<T>* temp = head;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        temp = tail;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};


#endif //STUDY_LINKEDLIST_H
