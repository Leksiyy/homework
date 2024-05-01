
#ifndef STUDY_MYSTRING_H
#define STUDY_MYSTRING_H

#include <iostream>

using namespace std;

class MyString {
private:
    static int count;
    char* str;
    int strSize;

public:
    MyString() {
        strSize = 80;
        str = new char[strSize];
        str[0] = '\0';
        count++;
    };
    MyString(int size) : MyString() {
        if (size < 1) {
            cerr << "Строка должна содержать хотя бы 1 символ" << endl;
            exit(1);
        }
        delete[] str;
        strSize = size + 1;
        str = new char[strSize];
        str[0] = '\0';
    }
    MyString(const char* inputedString) {
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
    ~MyString() {
        delete[] str;
    }
    char* getStr() {
        return str;
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
    void MyStrcpy(MyString & obj){
        delete[] str;
        str = new char[obj.strSize];
        strcpy(str, obj.str);
    }
    bool MyStrStr(const char * str) {

        for (int i = 0; i < strSize - strlen(str); ++i) {
            bool result = true;

                for (int j = 0; j < strlen(str); ++j) {
                    if (this->str[i+j] != str[j]) {
                        result = false;
                        break;
                    }
                }
            if (result) {
                return true;
            }
        }

        return false;
    }
    int MyChr(char c) {
        for (int i = 0; i < strSize; ++i) {
            if (str[i] == c) {
                return i;
            }
        }
        return -1;
    }
    int MyStrLen() {
        return strSize;
    }
    void MyStrCat(MyString& b) {

        int strLen = 0;
        while(str[strLen] != '\0') {
            strLen++;
        }
        int BstrLen = 0;
        while(b.str[BstrLen] != '\0') {
            BstrLen++;
        }

        char* newString = new char[strLen+BstrLen+1];
        for (int i = 0; i < strLen; ++i) {
            newString[i] = str[i];
        }
        for (int i = 0; i < BstrLen; ++i) {
            newString[i + strLen] = b.str[i];
        }
        newString[strLen+BstrLen] = '\0';
        delete[] str;
        str = newString;
    }
    void MyDelChr(char c) {
        int charCount = 0;
        for (int i = 0; i < strSize; ++i) {
            if (str[i] == c) {
                charCount++;
            }
        }
        if (charCount == 0) {
            return;
        } else {
            int newSize = strSize - charCount;
            char* newStr = new char[newSize];
            for (int i = 0, j = 0; i < strSize; ++i) {
                if (str[i] != c) {
                    newStr[j] = str[i];
                    j++;
                }
            }
            delete[] str;
            str = newStr;
        }
    }
    int MyStrCmp(MyString &b) {
        if (strSize > b.strSize) {
            return 1;
        } else if (strSize < b.strSize) {
            return -1;
        } else {
            return 0;
        }
    }
};
int MyString::count = 0;


#endif //STUDY_MYSTRING_H

//Задание 1
//Разработать класс MyString
//•	конструктор по умолчанию, позволяющий создать строку длиной 80 символов;
//•	конструктор, позволяющий создавать строку произвольного размера;
//•	конструктор, который создаёт строку и инициализирует её строкой, полученной от пользователя.
//•	деструктор;
//•	методы для ввода строк с клавиатуры и вывода строк на экран.
//•	void MyStrcpy(MyString & obj);// копирование строк
//•	bool MyStrStr(const char * str);// поиск подстроки в строке
//•	int  MyChr(char c); // поиск символа в строке(индекс найденного символа, либо -1)
//•	int MyStrLen();// возвращает длину строки
//•	void MyStrCat(MyString& b); // объединение строк
//•	void MyDelChr(char c); // удаляет указанный символ
//•	int MyStrCmp(MyString &b); // сравнение строк
//-1 – первая строка меньше чем вторая
//1 – первая больше чем вторая
//0 – строки равны!
//•	Статическое поле сохраняет кол-во созданных объектов.
//Поля класса :
//class MyString
//{
//    char * str; // указатель на строку
//    int length; // длина строки
//public:
//// методы класса
//};
