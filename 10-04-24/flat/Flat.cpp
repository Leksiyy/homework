#include "Flat.h"

int main () {
    Flat p;
    Flat p1(150, 15000);
    bool apple = p == p1;
    cout << apple << endl;
    p = p1;
    bool apple1 = p == p1;
    cout << apple1 << endl;
    char* hello = p>p1;
    cout << hello << endl;
    return 0;
}
