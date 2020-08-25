#include "help.h"

bool isOdzialCorrect(string IBAN) {
    int wagaBieg = 0;
    int wagi [7] = {7,1,3,9,7,1,3};
    int iloczyn;
    for(int i = 4; i <= 10; i++)
    {
        iloczyn = iloczyn + IBAN[i] * wagi[wagaBieg];
        wagaBieg++;
    }
    int kontrola = iloczyn % 10;
    bool isCorrect = (kontrola == IBAN[11]);
    return isCorrect;
};

string getBankNumber(string IBAN) {
    string bankIndentificator;
    for(int i = 4; i <= 7; i++)
    {
        bankIndentificator = bankIndentificator + to_string(IBAN[i] - '0');
    }
    return bankIndentificator;
};

bool isIBANCorrectForPL(string IBAN) {
    string bankNumber = IBAN.erase(0, 2);
    bool bankNumberEnougthLength = bankNumber.length() == 26;
    bool bankIsNumber = false;
    for (int i = 0; i < bankNumber.length(); i++)
       if (isdigit(bankNumber[i]) == false)
       {
           bankIsNumber = false;
       } else {
            bankIsNumber = true;
       }
    return bankNumberEnougthLength && bankIsNumber;
};
