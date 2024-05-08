#ifndef STUDY_STACK_H
#define STUDY_STACK_H

#include <iostream>
using namespace std;

//Змініть стек з першого завдання зі статичного типу на динамічний
//(за нестачі вільного місця потрібно змінити розмір внутрішнього
// масиву без втрати даних).

class Stack {
private:
    int size;
    char* stack;
    int _deletedIndexes[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int index;
public:

    Stack() : index(-1), size(10), stack(new char[size]) {};
    ~Stack(){if(stack != nullptr) delete[] stack;}

    void addChar(char c) {
        if (size < index) {
            size += 10;
            char* temp = new char[size];
            for (int i = 0; i < size - 10; ++i) {
                temp[i] = stack[i];
            }
            delete[] stack;
            stack = temp;
        }
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
        if (size > index + 20) { // что бы не был слишком большим и при добавлении частом не вызывались выделения памяти
            size -= 10;
            char* temp = new char[size];
            for (int i = 0; i == index; ++i) {
                temp[i] = stack[i];
            }
            delete[] stack;
            stack = temp;
        }
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
        char* temp = new char[10];
        delete[] stack;
        stack = temp;
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
