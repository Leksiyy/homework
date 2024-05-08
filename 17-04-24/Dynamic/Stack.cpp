#include "Stack.h"

int main() {
    Stack s;

    s.addChar('a');
    s.addChar('b');
    s.addChar('c');
    s.addChar('d');

    s.deleteChar();

    s.showTotalCountElements();

    s.addChar('d');
    s.addChar('e');
    s.addChar('f');
    s.addChar('g');
    s.addChar('h');
    s.addChar('i'); // 10
    s.addChar('j');

    cout << s.isFull() << endl;

    for (int i = 0; i < 11; ++i) {
        s.deleteChar();
    }

    cout << s.isEmpty() << endl;

    s.addChar('d');
    s.addChar('e');
    s.addChar('f');
    s.addChar('g');
    s.addChar('h');
    s.addChar('i');
    s.addChar('j');

    s.clearStack();

    s.addChar('g');
    cout << s.getFirstElement();

    return 0;
}