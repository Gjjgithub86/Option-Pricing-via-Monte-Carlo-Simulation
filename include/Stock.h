
#include "Entity_base.h"
#include "Date.h"

# ifndef STOCK_H
# define STOCK_H


class Stock: public Entity_base{
public:
    Stock(); //  default constructor
    Stock(Date date, double price);

private:

};

#endif