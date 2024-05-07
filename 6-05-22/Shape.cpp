#include "Shape.h"

int main() {
    Shape* s1 = new Square({5, 7}, 5);

    s1->Show();
    s1->Save();

    delete s1;
    return 0;
}
