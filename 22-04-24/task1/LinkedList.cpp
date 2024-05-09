#include "LinkedList.h"

int main() {
    LinkedList<int> list;

    list.addToHead(1);
    list.addToHead(2);
    list.addToTail(3);
    list.addToTail(4);

    cout << "List: ";
    list.Show();

    list.deleteFromHead();
    cout << "After DeleteFromHead: ";
    list.Show();

    list.deleteFromTail();
    cout << "After DeleteFromTail: ";
    list.Show();

    list.deleteAll();
    cout << "After DeleteAll: ";
    list.Show();


    return 0;
}