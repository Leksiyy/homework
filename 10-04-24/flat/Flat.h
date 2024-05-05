#ifndef STUDY_FLAT_H
#define STUDY_FLAT_H

#include <iostream>
using namespace std;

class Flat {
private:
    int price;
    int area;
public:
    Flat() {price = 0; area = 0;}
    Flat(int price, int area) {
        this->price = price;
        this->area = area;
    }
    bool operator==(const Flat& p) {
        if (this->area == p.area) {
            return 1;
        }
        return 0;
    }
    void operator=(Flat& p) {
        this->area = p.area;
        this->price = p.price;
    }
    char* operator>(Flat& p) {
        if(this->price == p.price) {
            return "Ціни рівні.\n";
        } else if (this->price > p.price) {
            return "Ціна обʼєкту на якому застосовано метод більша.\n";
        } else {
            return "Ціна обʼєкту на якому застосовано метод менша.\n";
        }
    }
};


#endif //STUDY_FLAT_H
