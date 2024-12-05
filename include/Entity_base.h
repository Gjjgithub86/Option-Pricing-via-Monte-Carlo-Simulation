#include "Date.h"

# ifndef ENTITY_BASE_H
# define ENTITY_BASE_H

class Entity_base{
public:
    Entity_base(); //  default constructor
    Entity_base(Date date, double price);
    Date getDate();
    double getPrice();
    void setDate(Date date);
    void setPrice(double price);

private:
    Date date;
    double price;
};

#endif