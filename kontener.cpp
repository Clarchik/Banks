#include "kontener.h"
#include "help.h"


List::List()
{
    this->head = nullptr;
}

List::~List()
{
    while(this->head)
    {
        node* killer = this->head;
        this->head = this->head->next;
        delete killer;
    }
}

Pracownik List::get()
{
    Pracownik pracownik = this->head->pracownik;
    node* killer = this->head;
    this->head = this->head->next;
    delete killer;
    return pracownik;
}

bool List::canGet()
{
    return this->head;
}


void List::push(Pracownik pracownik)
{
    if(!(this->head))
    {
        this->head = new node(pracownik, nullptr);
        return;
    }

    if(stoi(getBankNumber(pracownik.IBAN)) > stoi(getBankNumber(this->head->pracownik.IBAN)))
    {
        node* newNode = new node(pracownik, this->head);
        this->head = newNode;
        return;
    }

    node* iterator = this->head;
    while(iterator->next && stoi(getBankNumber(pracownik.IBAN)) < stoi(getBankNumber(iterator->next->pracownik.IBAN)))
    {
        iterator = iterator -> next;
    }

    if(iterator -> next)
    {
        node* newNode = new node(pracownik, iterator->next);
        iterator -> next = newNode;
    }
    else {
        iterator -> next = new node(pracownik, nullptr);
    }
}
