#include <iostream>
#include <fstream>
#include "dane.h"
#include "kontener.h"
#include "help.h"

using namespace std;


int main()
{
    ifstream pracownicyPlik("pracownicy.txt");

    ofstream iPKOPlik("1020.txt");
    ofstream mBank("1140.txt");
    ofstream AliorBank("2490.txt");

    string IBAN;
    List lista;

    while(pracownicyPlik >> IBAN)
    {
        Pracownik nowyPracownik;
        nowyPracownik.IBAN = IBAN;
        lista.push(nowyPracownik);
    }


    while(lista.canGet())
    {
        Pracownik pracownik = lista.get();
        if(isIBANCorrectForPL(pracownik.IBAN))
        {
            switch(stoi(getBankNumber(pracownik.IBAN)))
            {
                case 1020:
                    iPKOPlik << pracownik.IBAN << endl;
                    break;
                case 1140:
                    mBank << pracownik.IBAN << endl;
                    break;
                case 2490:
                    AliorBank << pracownik.IBAN << endl;
                    break;
            }
        }
    }

    return 0;
}
