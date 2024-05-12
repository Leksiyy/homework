#include "LinkedList.h"

int main() {
    LinkedList<int> list;

    list.addToHead(3);
    list.addToHead(2);
    list.addToHead(1);

    cout << "List after adding elements to head: ";
    list.show();

    list.addToTail(4);
    list.addToTail(5);

    cout << "List after adding elements to tail: ";
    list.show();

    list.deleteFromHead();
    list.deleteFromHead();

    cout << "List after deleting elements from head: ";
    list.show();

    list.deleteFromTail();

    cout << "List after deleting element from tail: ";
    list.show();

    list.insertAtPosition(10, 1);

    cout << "List after inserting element at position 1: ";
    list.show();

    list.deleteAtPosition(1);

    cout << "List after deleting element at position 1: ";
    list.show();

    int position = list.search(3);
    if (position != -1)
        cout << "Element 3 found at position " << position << endl;
    else
        cout << "Element 3 not found" << endl;

    list.replace(4, 7);

    cout << "List after replacing element 4 with 7: ";
    list.show();

    list.reverse();

    cout << "List after reversing: ";
    list.show();

    return 0;
}
