#include "Area.h"

//Створити абстрактний базовий клас з віртуальною функцією — площа.
// Створити похідні класи: прямокутник, коло, прямокутний трикутник,
// трапеція зі своїми функціями площі. Для перевірки визначити масив
// посилань на абстрактний клас, яким присвоюються адреси різних об’єктів.

int main() {
    Area* arr[4];

    arr[0] = new Triangle(5);
    arr[1] = new Circle(5);
    arr[2] = new RightTriangle(5);
    arr[3] = new Trapeze(5);

    cout << arr[0]->area() << endl;
    cout << arr[1]->area() << endl;
    cout << arr[2]->area() << endl;
    cout << arr[3]->area() << endl;


    return 0;
}