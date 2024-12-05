# include <string>
# include "Stock.h"
# include "Date.h"
# include "Entity_base.h"
# include "Contract.h"
using namespace std;

# ifndef DATASETFRAME_H
# define DATASETFRAME_H

class DataSetFrame{
public:
    DataSetFrame(string, Contract *, Stock *);
    double getMu();
    double getVol();
    double Prediction();
    void readCSV();
    int getLength();
    Stock getStock(int);
    double getRf();
    void setRf(double);
    int getMat();
    double getMean();
    Stock getS0();
    Contract getCon();

private:
    string df_name;
    Date buydate;
    Contract *contract;
    Stock *S0;
    int length, mat;
    double mu, mean, vol, Rf;
    Stock stockList[600]; // store the Stock in an array
};

#endif