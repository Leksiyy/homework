#ifndef STUDY_INSUFFICIENTFUNDSEXCEPTION_H
#define STUDY_INSUFFICIENTFUNDSEXCEPTION_H

#include <exception>
using namespace std;

class InsufficientFundsException : public exception {
private:
    char* message;
public:
    explicit InsufficientFundsException(char* message) : message(message) {};
    const char* what() const noexcept {
        return message;
    }
};


#endif //STUDY_INSUFFICIENTFUNDSEXCEPTION_H
