
#include "Entity_base.h"
#include "Contract.h"
#include "Date.h"



Contract::Contract(Date date, double price){
        this->cp = true; 
        this->setPrice(price);
        this->setDate(date);
}

Contract::Contract(Date date, double price, bool cp){
        this->cp = cp; 
        this->setPrice(price);
        this->setDate(date);
}

    
bool Contract::getCP(){return cp;}
void Contract::setCP(bool cp){this-> cp = cp;}