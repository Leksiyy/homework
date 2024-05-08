#ifndef STUDY_STACK_H
#define STUDY_STACK_H

#include <iostream>
using namespace std;

//Реалізуйте клас стеку для роботи з символами (символbний стек).
//Стек повинен мати фіксований розмір. Також реалізуйте набір операцій для роботи зі стеком:
//внесення символу в стек, видалення символу зі стеку, підрахунок кількості символів в стеці,
//перевірку, чи стек порожній, перевірку, чи стек повний, очищення стеку,
//отримання без видалення верхнього символу в стеці.

class Stack {
private:
    int size = 10;
    char stack[10]{};
    int _deletedIndexes[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int index;

public:
    Stack() : index(-1) {};

    void addChar(char c) {
        if(index < size - 1) {
            if (index == -1) {
                stack[index + 1] = c;
                index++;
                _deletedIndexes[index] = 111;
            }
            stack[index] = c;
            _deletedIndexes[index] = 111;
            index++;
        } else {
            cout << "stack overflow" << endl;
        }
    }
    void deleteChar() {
        if (index > -1) {
            _deletedIndexes[index] = 111;
            index--;
        } else {
            cout << "stack overflow" << endl;
        }
    }
    void showTotalCountElements() const {
        cout << index << endl;
    };
    bool isEmpty() {
        if(index == -1) return true;
        return false;
    }
    bool isFull() {
        if (index == 9) return true;
        return false;
    }
    void clearStack() {
        index = -1;
        for (int i = 0; i < size; ++i) {
            _deletedIndexes[i] = i;
        }
    }
    char getFirstElement() {
        if (index >= 0 && _deletedIndexes[0] != 0) {
            return stack[0];
        }
    }
};


#endif //STUDY_STACK_H
