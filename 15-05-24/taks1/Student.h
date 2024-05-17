#ifndef STUDY_STUDENT_H
#define STUDY_STUDENT_H

#include <iostream>
using namespace std;

class Student {
private:
    string name;
    char group;
public:
    Student() {};
    Student(string name, char group) {
        this->name = name;
        this->group = group;
    };
    string getName() {
        return name;
    }
    char getGroup() {
        return group;
    }
    void setName(string name) {
        this->name = name;
    }
    void setGroup(char group) {
        this->group = group;
    }
    void showInfo() {
        cout << "Name: " << getName() << '\n' << "Group: " << getGroup() << endl;
    }
};

#endif //STUDY_STUDENT_H
