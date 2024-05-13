#ifndef STUDY_PET_H
#define STUDY_PET_H
#include <iostream>
using namespace std;

//Створити базовий клас «Домашня тварина» і похідні класи «Собака», «Кішка», «Папуга», «Хом’як».
// За допомогою конструктора встановити ім’я кожної тварини і її характеристики.
//Реалізуйте для кожного з класів функції:
//■ Sound — видає звук тварини (пишемо текстом в консоль);
//■ Show — виводить на екран ім’я тварини;
//■ Type — виводить на екран назву її підвиду.

class Pet {
public:
    virtual void Sound() = 0;
    virtual void Show() = 0;
    virtual void Type() = 0;
};

class Dog : public Pet {
private:
    string name;
    string type;
public:
    Dog(string name, string type) {this->name = name; this->type = type;}
    void Sound() {
        cout << "Woof!!" << endl;
    }
    void Show() {
        cout << name << endl;
    }
    void Type() {
        cout << type << endl;
    }
};
class Cat : public Pet {
private:
    string name;
    string type;
public:
    Cat(string name, string type) {this->name = name; this->type = type;}
    void Sound() {
        cout << "Meow!!" << endl;
    }
    void Show() {
        cout << name << endl;
    }
    void Type() {
        cout << type << endl;
    }
};
class Parrot : public Pet {
private:
    string name;
    string type;
public:
    Parrot(string name, string type) {this->name = name; this->type = type;}
    void Sound() {
        cout << "Pi-pi-pi!!" << endl;
    }
    void Show() {
        cout << name << endl;
    }
    void Type() {
        cout << type << endl;
    }
};
class Hamster : public Pet {
private:
    string name;
    string type;
public:
    Hamster(string name, string type) {this->name = name; this->type = type;}
    void Sound() {
        cout << "Squonk!!" << endl;
    }
    void Show() {
        cout << name << endl;
    }
    void Type() {
        cout << type << endl;
    }
};


#endif //STUDY_PET_H
