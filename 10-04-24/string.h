#ifndef STUDY_STRING_H
#define STUDY_STRING_H
#include <iostream>
using namespace std;

class String {
private:
    char* str;
    int strSize;

public:
    String() {
        strSize = 80;
        str = new char[strSize];
        str[0] = '\0';
    };
    String(int size) : String() {
        if (size < 1) {
            cerr << "Строка должна содержать хотя бы 1 символ" << endl;
            exit(1);
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

};


#endif //STUDY_STRING_H
