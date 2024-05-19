#ifndef STUDY_ARGUMENTEXCEPTION_H
#define STUDY_ARGUMENTEXCEPTION_H

#include <exception>
using namespace std;

class ArgumentException : public exception {
private:
    char* message;
public:
    explicit ArgumentException(char* message) : message(message) {};

    const char* what() const noexcept {
        return message;
    }
};


#endif //STUDY_ARGUMENTEXCEPTION_H
