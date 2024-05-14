#ifndef STUDY_STRING_H
#define STUDY_STRING_H
#include <iostream>
#include "Exceptions.h"
using namespace std;

class String {
private:
    static int count;
    char* str;
    int strSize;

public:
    String() {
        strSize = 80;
        str = new char[strSize];
        str[0] = '\0';
        count++;
    };
    String(int size) : String() {
        if (size < 1) {
            throw Exceptions("Размер строки не может быть меньше нуля");
        }
        delete[] str;
        strSize = size + 1;
        str = new char[strSize];
        str[0] = '\0';
    }
    String(const char* inputedString) {
        int size = 0;
        while (inputedString[size] != '\0') {
            size++;
        }

        strSize = size + 1;
        str = new char[strSize];
        for (int i = 0; i < strSize; ++i) {
            str[i] = inputedString[i];
        }
        str[strSize - 1] = '\0';
        count++;
    }
    ~String() {
        delete[] str;
    }
    void getStr() {
        for (int i = 0; i < strSize; ++i) {
            cout << str[i];
        }
    }
    void cinStr(const char* inputString) {
        unsigned int size = 0;
        while (inputString[size] != '\0') {
            size++;
        }

        delete[] str;
        strSize = size + 1;
        str = new char[strSize];

        for (int i = 0; i < size; ++i) {
            str[i] = inputString[i];
        }
        str[size] = '\0';
    }
    static int getCount() {
        return count;
    }
};
int String::count = 0;

#endif //STUDY_STRING_H
