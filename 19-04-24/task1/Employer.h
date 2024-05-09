#ifndef STUDY_EMPLOYER_H
#define STUDY_EMPLOYER_H

//Створити абстрактний базовий клас Employer (службовець)
//з чисто віртуальною функцією Print (). Створіть три похідних класи:
//President, Manager, Worker.
//Перевизначите функцію Print() для виведення інформації,
//що відповідає кожному типу службовця.

#include <iostream>
using namespace std;

class Employer {
public:
    virtual void Print() = 0;
};

class President : public Employer{
    bool isHasCat;
public:
    void Print() {
        cout << "I am President!" << endl;
    }
};

class Manager : public Employer{
    int cardBalance;
public:
    void Print() {
        cout << "I am Manager!" << endl;
    }
};

class Worker : public Employer{
    string catName;
public:
    void Print() {
        cout << "I am Worker!" << endl;
    }
};

#endif //STUDY_EMPLOYER_H
