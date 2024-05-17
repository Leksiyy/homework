#include "Fraction.h"
#include "../task2/FileStream.h"

int main() {
    Fraction fr1{4, 7};
    Fraction fr{};

    FileStream file{"../data.txt"};

    file.save(fr1);
    file.load(fr);

    fr.showFraction();
    return 0;
}