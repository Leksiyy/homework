#ifndef STUDY_FILESTREAM_H
#define STUDY_FILESTREAM_H

#include <fstream>
#include "Student.h"
#include <string>
using namespace std;

class FileStream {
private:
    string _path;
public:
    FileStream(string name) : _path(name) {}

    void save(Student& st1) {
        ofstream file(_path);
        if (file.is_open()) {
            file << st1.getName() << " " << st1.getGroup() << '\n';
            file.close();
            cout << "Data saved correct." << endl;
        } else {
            cout << "File writing error." << endl;
        }
    };

    void load(Student& st1, bool isHaveNums = false) {
        ifstream file(_path);
        if (file.is_open()) {
            string data;
            file >> data;
            st1.setName(data);
            file >> data;
            st1.setGroup(data[0]);
            file.close();
        } else {
            cout << "File reading error.";
        }
    };
};


#endif //STUDY_FILESTREAM_H
