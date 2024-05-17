#ifndef STUDY_FILESTREAM_H
#define STUDY_FILESTREAM_H

#include <fstream>
#include "Fraction.h"
#include <string>
using namespace std;

class FileStream {
private:
    string _path;
public:
    FileStream(string name) : _path(name) {}

    void save(Fraction& st1) {
        ofstream file(_path);
        if (file.is_open()) {
            file << st1.getChiselnik() << " " << st1.getZnamennik() << '\n';
            file.close();
            cout << "Data saved correct." << endl;
        } else {
            cout << "File writing error." << endl;
        }
    };

    void load(Fraction& st1, bool isHaveNums = false) {
        ifstream file(_path);
        if (file.is_open()) {
            string data;
            file >> data;
            st1.setChiselnik(stoi(data));
            file >> data;
            st1.setZnamennik(stoi(data));
            file.close();
        } else {
            cout << "File reading error.";
        }
    };
};


#endif //STUDY_FILESTREAM_H
