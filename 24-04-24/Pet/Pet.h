#ifndef STUDY_PET_H
#define STUDY_PET_H

#include <iostream>
#include <string>
using namespace std;

// Створити базовий клас «Домашня тварина» і похідні класи
// «Собака», «Кішка», «Папуга». За допомогою конструктора
// встановити ім’я кожної тварини і її характеристики.

class Pet {
public:
    void makingSound() {
        cout << "Noice!" << endl;
    }
};

class Dog : public Pet {
    string name;
public:
    Dog(string name) {this->name = name;}
    void makingSound() {
        cout << "My name is " << name << "!" << endl;
    }
};
class Cat : public Pet {
    string name;
public:
    Cat(string name) {this->name = name;}
    void makingSound() {
        cout << "My name is " << name << "!" << endl;
    }
};
class Parrot : public Pet {
    string name;
public:
    Parrot(string name) {this->name = name;}
    void makingSound() {
        cout << "My name is " << name << "!" << endl;
    }
};

#endif //STUDY_PET_H
