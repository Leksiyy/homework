#ifndef STUDY_BANKACCOUNT_H
#define STUDY_BANKACCOUNT_H

#include "InsufficientFundsException.h"
#include "ArgumentException.h"

class BankAccount {
private:
    int _balance;
public:
    BankAccount() : _balance(0) {};
    explicit BankAccount(int b) : _balance(b) {};
    int getBalance() const  {
        return _balance;
    }
    void deposit(int deposit) {
        if (deposit < 1) {
            throw ArgumentException(const_cast<char*>("Negative deposit is not possible"));
        } else {
            _balance += deposit;
        }
    }
    void withdraw(int withdraw) {
        if (withdraw < 0) {
            throw ArgumentException(const_cast<char*>("Negative withdraw is not possible"));
        } else if (withdraw - _balance < 0) {
            throw InsufficientFundsException(const_cast<char*>("Insufficient funds"));
        } else {
            _balance -= withdraw;
        }
    }
};


#endif //STUDY_BANKACCOUNT_H
