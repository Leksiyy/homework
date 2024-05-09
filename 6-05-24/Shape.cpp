#include "Shape.h"

int main() {
    Shape* shapes[4];
    shapes[0] = new Square({0, 0}, 5);
    shapes[1] = new Rectangle({1, 1}, 3, 6);
    shapes[2] = new Circle({2, 2}, 8);
    shapes[3] = new Ellipse({3, 3}, 7, 9);

    for (int i = 0; i < 4; ++i) {
        shapes[i]->Show();
        cout << endl;
    }

    cout << endl << "*-*-*-**-*-*-**-*-*-**-*-*-**-*-*-**-*-*-*" << endl << endl;

    for (int i = 0; i < 4; ++i) {
        shapes[i]->Save();
    }

    Shape* newShapes[4];


    FILE* file = fopen("../data.txt", "r");
    while (!feof(file)) {
        char type[10];
        if (fscanf(file, "%s", type) == 1) {
            if (strcmp(type, "square") == 0) {
                Shape* square = newShapes[0]->Load(file);
                square->Show();
            } else if (strcmp(type, "rectangle") == 0) {
                Shape* rectangle = newShapes[1]->Load(file);
                rectangle->Show();
            } else if (strcmp(type, "circle") == 0) {
                Shape* circle = newShapes[2]->Load(file);
                circle->Show();
            } else if (strcmp(type, "ellipse") == 0) {
                Shape* ellipse = newShapes[3]->Load(file);
                ellipse->Show();
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
        delete shapes[i];
    }
    for (int i = 0; i < 4; ++i) {
        delete newShapes[i];
    }
}
