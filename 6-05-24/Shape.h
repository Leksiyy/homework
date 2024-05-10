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
    virtual Shape* Load(FILE* file) = 0;
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

    Shape* Load(FILE* file) {
        int x, y, side;
        if (fscanf(file, " %d %d %d", &x, &y, &side) == 3) {
            this->coordinates[0] = x;
            this->coordinates[1] = y;
            this->side = side;
            return this;
        }
        cout << "error! cant read shape from file!";
        return nullptr;
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
    Rectangle() {coordinates[0] = 0; coordinates[1] = 0; first_side = 0;};
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

    Shape* Load(FILE* file) {
        int x, y, side, sside;
        if (fscanf(file, "%d %d %d %d", &x, &y, &side, &sside) == 4) {
            this->coordinates[0] = x;
            this->coordinates[1] = y;
            this->first_side = side;
            this->second_side = sside;
            return this;
        }
        cout << "error! cant read shape from file!";
        return nullptr;
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
    Circle() {coordinates[0] = 0; coordinates[1] = 0; radius = 0;};
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

    Shape* Load(FILE* file) {
        int x, y, rad;
        if (fscanf(file, "%d %d %d", &x, &y, &rad) == 3) {
            this->coordinates[0] = x;
            this->coordinates[1] = y;
            this->radius = rad;
            return this;
        }
        cout << "error! cant read shape from file!";
        return nullptr;
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
    Ellipse() {coordinates[0] = 0; coordinates[1] = 0; first_side = 0; second_side = 0;};
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

    Shape* Load(FILE* file) {
        int x, y, side, sside;
        if (fscanf(file, "%d %d %d %d", &x, &y, &side, &sside) == 4) {
            this->coordinates[0] = x;
            this->coordinates[1] = y;
            this->first_side = side;
            this->second_side = sside;
            return this;
        }
        cout << "error! cant read shape from file!";
        return nullptr;
    }
};


#endif //STUDY_SHAPE_H