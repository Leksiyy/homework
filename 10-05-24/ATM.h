#ifndef STUDY_ATM_H
#define STUDY_ATM_H

#include "BankAccount.h"
#include <iostream>
using namespace std;

class ATM {
public:
    ATM() {};
    void WithdrawMoney(BankAccount& account, int withdraw) {
        try {
            account.withdraw(withdraw);
            cout << "Operation success, your balance " <<
            account.getBalance() << ".\n";
        } catch (const ArgumentException& e) {
            cout << "Error: " << e.what() << endl;
        } catch (const InsufficientFundsException& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
};


#endif //STUDY_ATM_H
