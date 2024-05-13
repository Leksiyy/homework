#include "Pet.h"

int main() {
    Dog dog{"Walley", "simple dog"};
    Cat cat{"Boris", "street cat"};
    Parrot Parrot{"Varleriy", "straus"};
    Hamster Hamster{"Aleksandr", "just a fat humster"};

    dog.Sound();
    dog.Show();
    dog.Type();

    cout << endl;

    cat.Sound();
    cat.Show();
    cat.Type();

    cout << endl;

    Parrot.Sound();
    Parrot.Show();
    Parrot.Type();

    cout << endl;

    Hamster.Sound();
    Hamster.Show();
    Hamster.Type();


    return 0;
}