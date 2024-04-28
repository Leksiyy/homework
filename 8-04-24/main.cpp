#include <iostream>
using namespace std;

class Fraction {
    int numerator;
    int denominator;
public:
    Fraction() : numerator(0), denominator(1) {};
    Fraction(int num, int den) : numerator(num), denominator(den) {
        if (!denominator) {
            cerr << "Знаменник не може дорівнювати нулю." << endl;
            exit(1);
        }
        if (denominator < 0) { // якщо знаменник менший за 0 - інвертую обидві чатсини дробу
            numerator = -numerator;
            denominator = -denominator;
        }
    };

    int getNumerator() const {return numerator;};
    int getDenominator() const{return denominator;};

    void setNumerator(int num){numerator = num;};
    void setDenominator(int den){
        if (den == 0) {
            cerr << "Знаменник не може дорівнювати нулю." << endl;
            exit(1);
        }
        if (den < 0) {
            numerator = -numerator;
            denominator = -denominator;
        } else {
            denominator = den;
        }
    };
};

int main() {
    Fraction f;
    f.setNumerator(1);
    f.setDenominator(2);

    cout << "дроб: " << f.getNumerator() << "/" << f.getDenominator() << endl;
    return 0;
}