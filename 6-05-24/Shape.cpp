#include "Shape.h"

int main() {
    Shape* s1 = new Square({5, 7}, 5);

    s1->Show();
    s1->Save();
    Shape* s2 = new Square;
    s2->Load();
    s2->Show();

    delete s1;
    delete s2;
    return 0;
}
