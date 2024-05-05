#ifndef STUDY_OVERCOAT_H
#define STUDY_OVERCOAT_H

#include <iostream>
using namespace std;

class Overcoat {
private:
    char* type;
    int price;
public:
    Overcoat() { type = "None"; price = 0; }
    Overcoat(char* type, int price) {
        this->type = type;
        this->price = price;
    }
    void setPrice(int p) {
        if(p < 0) {
            this->price = 0;
        } else {
            this->price = p;
        }
    }
    void setType(const char* t) {
        *(this->type) = *(t);
    }
    int getPrice() const {
        return this->price;
    }
    char* getType() const {
        return this->type;
    }
    bool operator==(const Overcoat& obj) const {
        return *(this->type) == *(obj.type);
    }
    void operator=(const Overcoat& obj) {
        this->type = obj.type;
        this->price = obj.price;
    }
    bool operator>(const Overcoat& obj) const {
        if (*(this->type) == *(obj.type)) {
            return this->price > obj.price;
        } else exit(1);
    }
};


#endif //STUDY_OVERCOAT_H
