#include "string.h"

int main() {
    cout << "hello\n";

    String str1{};
    String str2{20};
    String str3{"Hello IsStep!!!"};
    str3.getStr();
    str1.cinStr("\nprogramming process 80%..");
    str1.getStr();
    return 0;
}