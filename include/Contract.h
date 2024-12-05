#include "Entity_base.h"
#include "Date.h"


# ifndef CONTRACT_H
# define CONTRACT_H


class Contract: public Entity_base{
public:
    Contract(Date date, double price);
    Contract(Date date, double price, bool cp);
    
    bool getCP();
    void setCP(bool cp);


private:
    bool cp;  // true for call; false for Put
};

#endif