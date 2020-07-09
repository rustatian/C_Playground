//
// Created by valery on 08/11/2019.
//

#include <string>
#include "../include/templates.hpp"


//int max(int a, int b) {
//    if (a > b)
//        return a;
//    return b;
//}
//
//double max(double a, double b) {
//    if (a > b)
//        return a;
//    return b;
//}

template<typename T>
T max(T a, T b) {
    if (a > b)
        return a;
    return b;
}

struct EUBankAccount {
    std::string IBAN;
    int amount;
};

struct UKBankAccount {
    std::string sortNumber;
    std::string accountNumber;
    int amount;
};

template<typename BankAccount>

int getMaxAmount(const BankAccount &a, const BankAccount &b) {
    if (a.amount > b.amount) {
        return a.amount;
    }
    return b.amount;
}

///////////////////
template<typename T>
T createFrom(const T &other) {
    return T(other);
}

class A {

};

int main(int, char **) {
    max(3, 4);
    max(3.4, 3.5);
    max<int>(2, 4);

    EUBankAccount euacc1{"IBAN1", 1000};
    EUBankAccount euacc2{"IBAN2", 2000};

    getMaxAmount(euacc1, euacc2);

    UKBankAccount ukacc1{"IBAN3", "accnum1", 4000};
    UKBankAccount ukacc2{"IBAN4", "accnum2", 4000};

    getMaxAmount(ukacc2, ukacc1);

    A a;

    A& a_ref1 = a;
    A&& a_ref2 = A();
}