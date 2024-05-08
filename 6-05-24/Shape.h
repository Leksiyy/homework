#ifndef STUDY_SHAPE_H
#define STUDY_SHAPE_H

#include <iostream>
#include <cstdio>
using namespace std;

class Shape {
public:
    virtual ~Shape() = default;
    virtual void Show() = 0;
    virtual void Save() const = 0;
    virtual void Load() = 0;
};

class Square : public Shape {
private:
    int coordinates[2] {};
    int side;
public:
    Square() {coordinates[0] = 0; coordinates[1] = 0; side = 0;};
    Square(initializer_list<int> coord, int s) : side(s) {
        if (coord.size() != 2) {
            cout << "Initializer list must contain 2 elements";
        }

        coordinates[0] = *coord.begin();
        coordinates[1] = *(coord.end() - 1);
    }
    void Show() {
        cout << "coordinates:\nx: " << coordinates[0] << "\ny: " << coordinates[1] << "\nside: " << side << endl;
    }
    void Save () const {
        const char PATH[] = "../data.txt";
        FILE *file;
        file = fopen(PATH, "a");
        if (file) {
            fprintf(file, "square %d %d %d\n", coordinates[0], coordinates[1], side);
            fclose(file);
        }
    }

    void Load() {
        const char PATH[] = "../data.txt";
        FILE *file;
        file = fopen(PATH, "r");
        if (file) {
            const char searchType[] = "square";
            int x, y, side;
            char currentType[15];

            while (!feof(file)) {
                if (fscanf(file, "%14s %d %d %d", currentType, &x, &y, &side) != 4) {
                    continue;
                }

                if (strcmp(currentType, searchType) == 0) {
                    this->coordinates[0] = x;
                    this->coordinates[1] = y;
                    this->side = side;
                }
            }
            fclose(file);
        }
    }
};

class Rectangle : public Shape {
private:
    int coordinates[2] {};
    int first_side;
    int second_side;
public:
    Rectangle(initializer_list<int> coord, int fs, int ss) : first_side(fs), second_side(ss) {
        if (coord.size() != 2) {
            cout << "Initializer list must contain 2 elements";
        }

        coordinates[0] = *coord.begin();
        coordinates[1] = *(coord.end() - 1);
    }
    void Show() {
        cout << "coordinates:\nx: " << coordinates[0] << "\ny: " << coordinates[1];
        cout << "\nfirst side: " << first_side << "\nsecond side: " << second_side << endl;
    }
    void Save () const {
        const char PATH[] = "../data.txt";
        FILE *file;
        file = fopen(PATH, "a");
        if (!file) return;
        fprintf(file, "rectangle %d %d %d %d\n", coordinates[0], coordinates[1], first_side, second_side);
        fclose(file);
    }

    void Load() {
        const char PATH[] = "../data.txt";
        FILE *file;
        file = fopen(PATH, "a");
        if (file) {
            const char searchType[] = "rectangle";
            int x, y, fside, sside;
            char currentType[15];

            while (feof(file)) {
                if (fscanf(file, "%14s %d %d %d %d", currentType, &x, &y, &fside, &sside) != 4) {
                    continue;
                }

                if (strcmp(currentType, searchType) == 0) {
                    this->coordinates[0] = x;
                    this->coordinates[1] = y;
                    this->first_side = fside;
                    this->second_side = sside;
                }
            }
            fclose(file);
        }
    }
};

class Circle : public Shape {
private:
    int coordinates[2] {};
    int radius;
public:
    Circle(initializer_list<int> coord, int r) : radius(r) {
        if (coord.size() != 2) {
            cout << "Initializer list must contain 2 elements";
        }

        coordinates[0] = *coord.begin();
        coordinates[1] = *(coord.end() - 1);
    }
    void Show() {
        cout << "coordinates:\nx: " << coordinates[0] << "\ny: " << coordinates[1] << "\nradius: " << radius << endl;
    }
    void Save () const {
        const char PATH[] = "../data.txt";
        FILE *file;
        file = fopen(PATH, "a");
        if (!file) return;
        fprintf(file, "circle %d %d %d\n", coordinates[0], coordinates[1], radius);
        fclose(file);
    }

    void Load()  {
        const char PATH[] = "../data.txt";
        FILE *file;
        file = fopen(PATH, "a");
        if (file) {
            const char searchType[] = "circle";
            int x, y, rad;
            char currentType[15];

            while (feof(file)) {
                if (fscanf(file, "%14s %d %d %d", currentType, &x, &y, &rad) != 3) {
                    continue;
                }

                if (strcmp(currentType, searchType) == 0) {
                    this->coordinates[0] = x;
                    this->coordinates[1] = y;
                    this->radius = rad;
                }
            }
            fclose(file);
        }
    }
};

class Ellipse : public Shape {
private:
    int coordinates[2] {};
    int first_side;
    int second_side;
public:
    Ellipse(initializer_list<int> coord, int fs, int ss) : first_side(fs), second_side(ss) {
        if (coord.size() != 2) {
            cout << "Initializer list must contain 2 elements";
        }

        coordinates[0] = *coord.begin();
        coordinates[1] = *(coord.end() - 1);
    }
    void Show() {
        cout << "coordinates:\nx: " << coordinates[0] << "\ny: " << coordinates[1];
        cout << "\nfirst side: " << first_side << "\nsecond side: " << second_side << endl;
    }
    void Save () const {
        const char PATH[] = "../data.txt";
        FILE *file;
        file = fopen(PATH, "a");
        if (!file) return;
        fprintf(file, "ellipse %d %d %d %d\n", coordinates[0], coordinates[1], first_side, second_side);
        fclose(file);
    }

    void Load() {
        const char PATH[] = "../data.txt";
        FILE *file;
        file = fopen(PATH, "a");
        if (file) {
            const char searchType[] = "ellipse";
            int x, y, fside, sside;
            char currentType[15];

            while (feof(file)) {
                if (fscanf(file, "%14s %d %d %d %d", currentType, &x, &y, &fside, &sside) != 4) {
                    continue;
                }

                if (strcmp(currentType, searchType) == 0) {
                    this->coordinates[0] = x;
                    this->coordinates[1] = y;
                    this->first_side = fside;
                    this->second_side = sside;
                }
            }
            fclose(file);
        }
    }
};


#endif //STUDY_SHAPE_H
