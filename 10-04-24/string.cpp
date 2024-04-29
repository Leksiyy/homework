#include "string.h"

int main() {
    cout << "hello\n";

    String str1{};
    cout << sizeof(str1) << endl;
    String str2{20};
    cout << sizeof(str2) << endl;
    String str3{"Hello IsStep!!!"};
    cout << sizeof(str3) << endl;
    str3.getStr();
    return 0;
}