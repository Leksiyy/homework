#include "string.h"

int main() {
    cout << "hello\n";

    String str1{};
    String str2{20};
    String str3{"Hello IsStep!!!"};
    str3.getStr();
    str1.cinStr("\nprogramming process 80%..");
    str1.getStr();
    cout << endl << String::getCount() << endl;
    try {
        String strException{-2};
    } catch (const Exceptions& ex) {
        cerr << "Error: " << ex.what() << endl;
    }
    return 0;
}