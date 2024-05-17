#ifndef STUDY_FRACTION_H
#define STUDY_FRACTION_H

using namespace std;
#include <iostream>

class Fraction {
private:
    int chiselnik; // Вот оправдание если я забыл поменять названия:
    int znamennik; // Я делал это здаание когда уже не было света, и загуглить как будет переводиться это я не смог =(
public:
    Fraction() = default;
    Fraction(int num1, int num2) : chiselnik(num1), znamennik(num2) {}

    void setChiselnik(int num) {
        this->chiselnik = num;
    }
    void setZnamennik(int num) {
        this->znamennik = num;
    }

    int getChiselnik() {
        return chiselnik;
    }
    int getZnamennik() {
        return znamennik;
    }

    void showFraction() {
        cout << chiselnik << "/" <<  znamennik << endl;
    }
};


#endif //STUDY_FRACTION_H
