#include "MyString.h"

int main() {
    MyString string1;
    MyString string2{"hello"};

    string1.MyStrcpy(string2);
    cout << string1.getStr() << endl;

    cout << string2.MyStrStr("lo") << endl;
    cout << string2.MyStrStr("w") << endl;

    cout << string1.MyChr('i') << endl;
    cout << string1.MyChr('o') << endl;

    cout << string2.MyStrLen() << endl;

    MyString string3{" world!!!"};
    string1.MyStrCat(string3);
    cout << string1.getStr() << endl;

    string1.MyDelChr('!');
    cout << string1.getStr() << endl;

    cout << string2.MyStrCmp(string3) << endl;
    cout << string2.MyStrCmp(string2) << endl;

    return 0;
}