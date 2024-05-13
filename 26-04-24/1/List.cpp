#include "List.h"

int main() {
    Stack stack;
    Queue queue;

    stack.insert(10);
    stack.insert(20);
    stack.insert(30);
    stack.display();
    stack.remove();
    stack.display();

    cout << endl;

    queue.insert(100);
    queue.insert(200);
    queue.insert(300);
    queue.display();
    queue.remove();
    queue.display();

    return 0;
}
