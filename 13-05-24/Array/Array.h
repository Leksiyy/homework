#ifndef STUDY_ARRAY_H
#define STUDY_ARRAY_H

#include "Exceptions.h"
#include <iostream>
using namespace std;

class Array {
private:
    int size;
    int* array;

    void sortArray(int left, int right) {
        if (left > right) return;
        int p = array[(left + right) / 2];
        int i = left;
        int j = right;
        while(i <= j) {
            while(this->array[i] < p) i++;
            while(this->array[j] > p) j--;
            if (i <= j) {
                int temp = this->array[i];
                this->array[i] = this->array[j];
                this->array[j] = temp;
                i++;
                j--;
            }
        }
        sortArray(left, j);
        sortArray(i, right);
    }
public:
    Array() {size = 0; array = nullptr;} // default

    Array(int size, int* arr) : size(size), array(arr) {this->array = arr;} // custom

    Array(const Array& p) : size(p.size), array(new int[size]) { // copy
        for (int i = 0; i < size; ++i) {
            this->array[i] = p.array[i]; // копирую поэлементно
        }
    }

    Array(Array&& b) : size(b.size), array(b.array) { // move
        b.size = 0;
        b.array = nullptr;
    }

    ~Array(){ if (array != nullptr) delete[] array; } // destructor

    int* getArray() const {
        return array;
    }
    int getArraySize() const {
        return size;
    }
    void setArray(int* arr, int s) {
        if (s < 0) throw Exceptions("Размер не может быть меньше нуля"); ////////////////////////////////////////////////
        if (arr != nullptr) {
            if (array != nullptr) {
                delete[] array;
                this->array = arr;
            } else {
                this->array = arr;
            }
            this->size = s;
        }
    }
    void setSize(int s) {
        if (s < 0) throw Exceptions("Размер не может быть меньше нуля"); ////////////////////////////////////////////////
        int* newArr = new int[s];
        for (int i = 0; i < size; ++i) {
            newArr[i] = array[i];
        }
        delete[] array;
        array = newArr;
        this->size = s;
    }
    void addElement(int where, int element) { // 0 - left; 1 - right;
        if (where < 0 || where > 1) {
            throw Exceptions("Не правильно указан индекс вставки"); ///////////////////////////////////////////////////////////////////////////
        };
        if (where) {
            int* newArr = new int[this->size + 1];
            for (int i = 0; i < this->size; ++i) {
                newArr[i] = this->array[i];
            }
            newArr[this->size] = element;
            if (array == nullptr) delete[] this->array;
            this->array = newArr;
            this->size++;
        } else {
            int* newArr = new int[this->size + 1];
            for (int i = 0; i < this->size; ++i) {
                newArr[i+1] = this->array[i];
            }
            newArr[0] = element;
            if (array == nullptr) delete[] this->array;
            this->array = newArr;
            this->size++;
        }
    }
    void showArray() {
        for (int i = 0; i < this->size; ++i) {
            cout << array[i] << " ";
        }
        cout << '\n';
    }
    void sortArray() { // quick sort
        sortArray(0, size - 1); // incapsulated
    }
    int getMin() {
        int totalAnswer = this->array[0];
        for (int i = 1; i < size; ++i) {
            if(this->array[i] < totalAnswer) totalAnswer = this->array[i];
        }
        return totalAnswer;
    }
    int getMax() {
        int totalAnswer = this->array[0];
        for (int i = 1; i < size; ++i) {
            if(this->array[i] > totalAnswer) totalAnswer = this->array[i];
        }
        return totalAnswer;

    }
};


#endif //STUDY_ARRAY_H
