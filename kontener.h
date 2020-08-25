#ifndef kontener_h
#define kontener_h

#include "dane.h"



class List {
private:
    class node {
        public:
            Pracownik pracownik;
            node* next;

            node(Pracownik pracownik, node* next)
            {
                this->pracownik = pracownik;
                this->next = next;
            }
    };
    node* head;
        public:
            List();
            ~List();
            void push(Pracownik);
            bool canGet();
            Pracownik get();
};
#endif // kontener_h
