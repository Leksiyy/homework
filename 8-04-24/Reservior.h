//
// Created by Алексей on 02.05.2024.
//

#ifndef STUDY_RESERVIOR_H
#define STUDY_RESERVIOR_H

#include <iostream>
#include <cstdio>
using namespace std;

    class Reservior {
    private:
        int width;
        int length;
        int max_depth;
        char* type;
    public:
        Reservior() { width = 0; length = 0; max_depth = 0; type = nullptr;}
        explicit Reservior(int width, int length, int max_depth, const char* type) {
            this->width = width;
            this->length = length;
            this->max_depth = max_depth;
            int strSize = 0;
            while (type[strSize] != '\0') {
                strSize++;
            }
            char* newType = new char[strSize+1];
            for (int i = 0; i < strSize; ++i) {
                newType[i] = type[i];
            }
            newType[strSize] = '\0';
            this->type = newType;
        }
        ~Reservior(){
            if (type != nullptr) {
                delete[] type;
            }
        }

        void setWidth(int w) {
            if (w < 0) {
                cout << "Ширина не може бути менше нуля." << endl;
            } else {
                this->width = w;
            }
        }
        void setLength(int l) {
            if (l < 0) {
                cout << "Довжина не може бути менше нуля." << endl;
            } else {
                this->length = l;
            }
        }
        void setMax_depth(int d) {
            if (d < 0) {
                cout << "Максимальна глибина не може бути менше нуля." << endl;
            } else {
                this->max_depth = d;
            }
        }
        void setType(const char* t) {
            int strSize = 0;
            while (t[strSize] != '\0') {
                strSize++;
            }
            char* newType = new char[strSize+1];
            for (int i = 0; i < strSize; ++i) {
                newType[i] = t[i];
            }
            newType[strSize] = '\0';
            delete[] this->type;
            this->type = newType;
        }
        int getWidth() const {
            return width;
        }
        int getLength() const {
            return length;
        }
        int getMax_depth() const {
            return max_depth;
        }
        char* getType() const {
            return type;
        };
        int approximate_volume() const {
            return width * length * max_depth;
        }
        int calc_area() const {
            return width * length;
        }
        int isTheSameType(const Reservior& b) const {
            return *(this->type) == *(b.type);
        }
        char* area_comparison(const Reservior& b) const {
            if (*(this->type) == *(b.type)) {
                if (this->calc_area() == b.calc_area()) {
                    return "Площі рівні.\n";
                } else if (this->calc_area() > b.calc_area()) {
                    return "Площа обʼєкта на якому було застосовано метод більшa \n";
                    return "ніж площа обʼєкту який переданий в якості аргументу.\n";
                } else {
                    return "Площа обʼєкту який переданий в якості аргументу більшa.\n";
                    return "ніж площа обʼєкта на якому було застосовано метод.\n";
                }
            } else {
                return "Різні типи обʼєктів.\n";
            }
        }
        void copyObj(const Reservior& b) {
            this->width = b.width;
            this->length = b.length;
            this->max_depth = b.max_depth;
            if (b.type == nullptr) {
                if (this->type == nullptr) {
                    return;
                } else {
                    delete[] type;
                    type = nullptr;
                }
            } else {
                if (this->type == nullptr) {
                    int strSize = 0;
                    while (b.type[strSize] != '\0') {
                        strSize++;
                    }
                    char* newType = new char[strSize+1];
                    for (int i = 0; i < strSize; ++i) {
                        newType[i] = b.type[i];
                    }
                    newType[strSize] = '\0';
                    this->type = newType;
                } else {
                    int strSize = 0;
                    while (b.type[strSize] != '\0') {
                        strSize++;
                    }
                    char* newType = new char[strSize+1];
                    for (int i = 0; i < strSize; ++i) {
                        newType[i] = b.type[i];
                    }
                    newType[strSize] = '\0';
                    delete[] this->type;
                    this->type = newType;
                }
            }
        }

//        int width;
//        int length;
//        int max_depth;
//        char* type;
        void writeToFile() {
            const char PATH[] = "../data.txt";
            FILE* file;
            file = fopen(PATH, "w");
            if (file != nullptr) {
                fputs("Ширина: ", file);
                fprintf(file, "%d", this->width);
                fputc('\n', file);
                fputs("Довжина: ", file);
                fprintf(file, "%d", this->length);
                fputc('\n', file);
                fputs("Максимальна глибина: ", file);
                fprintf(file, "%d", this->max_depth);
                fputc('\n', file);
                fputs("Тип: ", file);
                fputs(this->type, file);
                fputc('\n', file);
                fclose(file);
            } else {
                cerr << "Файл не знайдено.";
                exit(1);
            }
        }
};


#endif //STUDY_RESERVIOR_H
