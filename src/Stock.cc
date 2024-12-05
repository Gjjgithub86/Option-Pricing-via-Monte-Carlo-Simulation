#include "Stock.h"
#include "Date.h"
#include "Entity_base.h"



Stock::Stock(){}

Stock::Stock(Date date, double price){
        this->setPrice(price);
        this->setDate(date);
}