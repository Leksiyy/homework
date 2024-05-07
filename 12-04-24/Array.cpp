#include "Array.h"

//  +   Створіть клас Array. Клас Array — це клас динамічного масиву.
//  +   Розмір масиву може бути переданий як параметр або
//  +   заданий за допомогою виклику функції-члена.
//  +   Клас повинен дозволяти заповнювати масив значеннями,
//  +   відображати вміст масиву, змінювати розмір масиву,
//  +   сортувати масив, визначати мінімальне і максимальне значення.
//  +   Клас повинен містити набір конструкторів (конструктор
//  +   копіювання обов’язковий), деструктор.
//  +   Додати в клас Array конструктор переміщення.

int main() {
    // тест конструктора за замовчуванням
    Array a1;
    cout << "пустий масив:" << endl;
    a1.showArray(); // нічого не виводиться

    cout << endl << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl << endl;

    // тест користувацького конструктора
    int initialData[] = {3, 1, 4, 1, 5, 9};
    Array a2(6, initialData); // передав розмір та массив
    cout << "початковий масив:" << endl;
    a2.showArray(); // 3 1 4 1 5 9

    cout << endl << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl << endl;

    // тест конструктора копіювання
    Array a3(a2); // із a2 в a3
    cout << "копія початкового масиву:" << endl;
    a3.showArray(); // 3 1 4 1 5 9

    cout << endl << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl << endl;

    // тест конструктора руху
    Array a4(move(a2)); // рухаю данні із a2 в a4
    cout << "масив після переміщення:" << endl;
    a4.showArray(); // 3 1 4 1 5 9
    cout << "початковий масив післе переміщення:" << endl;
    //temp.showArray(); // нічого не повинно вивестись

    cout << endl << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl << endl;

    // тест сортування
    cout << "сортований масив:" << endl;
    a4.sortArray();
    a4.showArray(); // 1 1 3 4 5 9

    cout << endl << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl << endl;

    // тест на додавання элементу
    a4.addElement(1, 10); // додаю элемент справа
    cout << "масив після додавання элемента справа:" << endl;
    a4.showArray(); // 1 1 3 4 5 9 10

    a4.addElement(0, 0); // додаю элемент зліва
    cout << "масив після додавання элементу зліва:" << endl;
    a4.showArray(); // 0 1 1 3 4 5 9 10

    cout << endl << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl << endl;

    // тест методів які повертають максимальне та мінімальне значення //////// getMin getMax TOO!!
    int minVal = a4.getMin(); // 0
    int maxVal = a4.getMax(); // 10
    cout << "мінімальне значення в масиві: " << minVal << endl;
    cout << "максимальне значення в масиві: " << maxVal << endl;

    cout << endl << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl << endl;

    // тест на зміну розміру массиву //////////////// NEED TO ONE MORE TEST AFTER FIX PREVIOUS MISTAKES!!!
    a4.setSize(4); // обрізаю массив до 4 элементів
    cout << "Массив после изменения размера:" << endl;
    a4.showArray(); // 0 1 1 3

    cout << endl << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl << endl;

    cout << "тестування закінчено." << endl;

    return 0;
}