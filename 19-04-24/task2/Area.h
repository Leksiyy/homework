#ifndef STUDY_AREA_H
#define STUDY_AREA_H

#include <iostream>
using namespace std;

//Створити абстрактний базовий клас з віртуальною функцією — площа.
// Створити похідні класи: прямокутник, коло, прямокутний трикутник,
// трапеція зі своїми функціями площі. Для перевірки визначити масив
// посилань на абстрактний клас, яким присвоюються адреси різних об’єктів.

class Area {
public:
    virtual int area() = 0;
};

class Triangle : public Area{
    int side;
public:
    Triangle(int s) : side(s) {};
    int area() {
        return side*2;
    }
};

class Circle : public Area{
    int side;
public:
    Circle(int s) : side(s) {};
    int area() {
        return side*2;
    }
};

class RightTriangle : public Area{
    int side;
public:
    RightTriangle(int s) : side(s) {};
    int area() {
        return side*2;
    }
};

class Trapeze : public Area{
    int side;
public:
    Trapeze(int s) : side(s) {};
    int area() {
        return side*2;
    }
};

#endif //STUDY_AREA_H
