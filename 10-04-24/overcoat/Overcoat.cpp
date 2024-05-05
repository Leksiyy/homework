#include "Overcoat.h"

int main() {
    Overcoat r1("Jacket", 1300);
    Overcoat r2("Dresses", 2100);
    Overcoat r3("Dresses", 2600);
    Overcoat r4;
    bool apple = r1 == r2;
    bool banana = r2 == r3;
    cout << apple << " " << banana << endl;
    r4 = r1;
    cout << r4.getType() << " " << r4.getPrice() << endl;
    bool pinaple = r2>r3;
    bool pinaple1 = r3>r2;
    cout << pinaple << " " << pinaple1;

    return 0;
}