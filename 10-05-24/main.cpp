#include "BankAccount.h"
#include "ATM.h"

using namespace std;

int main() {
    BankAccount acc{100};
    ATM wat;

    cout << acc.getBalance() << endl;
    acc.deposit(100);
    cout << acc.getBalance() << endl;
    wat.WithdrawMoney(acc, 200);
    cout << acc.getBalance() << endl;

    try {
        acc.deposit(-100);
    } catch (const ArgumentException& e) {
        cout << "Error: " << e.what() << endl;
    }
    wat.WithdrawMoney(acc, -200);

    return 0;
}