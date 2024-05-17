#include "Student.h"
#include "FileStream.h"

int main() {
    Student st1{"Boris", 'A'};
    Student st2;

    FileStream file{"../data.txt"};

    file.save(st1);
    file.load(st2);

    st2.showInfo();

    return 0;
}
