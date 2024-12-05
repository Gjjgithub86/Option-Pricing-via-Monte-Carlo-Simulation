    
    #include "Entity_base.h"
    #include "Date.h"
    
    
    Entity_base::Entity_base(){} //  default constructor
    Entity_base::Entity_base(Date date, double price): date(date), price(price){}
    Date Entity_base::getDate(){return this->date;}
    double Entity_base::getPrice(){return this->price;}
    void Entity_base::setDate(Date date){this->date = date;}
    void Entity_base::setPrice(double price){this->price = price;}