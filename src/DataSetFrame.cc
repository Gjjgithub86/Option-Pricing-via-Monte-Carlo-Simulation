#include "DataSetFrame.h"
#include "Contract.h"
#include "Date.h"
#include "Stock.h"
#include "Entity_base.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cmath>
#include <random>

using namespace std;


DataSetFrame::DataSetFrame(string df_name, Contract *contract, Stock *S0):
    contract(contract),S0(S0){

    // initialization 
    this->df_name = df_name;
    this->length = 0;
    this->mat = S0->getDate().diff(contract->getDate());
    this->buydate = S0->getDate();
    this->Rf = 0.05;

    //read the csv file to store the stock into the stock list
    cout << "Opening the file '" << df_name << "'......" << endl;
    readCSV();
}

void DataSetFrame::readCSV(){
    vector <string> row;
    string line, words, word;
 
    fstream file (this->df_name, ios::in);
    if(file.is_open()){
        cout << "Open the file '" << this->df_name <<  "' successfully......" << endl;
        
        
        while(getline(file, line, '\n')){
            row.clear();
            stringstream S1(line);


            // to skip the first line
            if (!isdigit(line[0])){
                continue;
            }

            while(getline(S1, words, ',')){
                if (words.find('/') != string::npos){
                    stringstream S2(words);
                    while(getline(S2, word, '/')){
                        row.push_back(word);
                    }
                }else{
                    row.push_back(words);
                }
            }
            (this->stockList)[this->length] = Stock(Date(stoi(row[1]),stoi(row[2]),stoi(row[0])),stod(row[3]));
            this->length++;
        }
    }else{
        cerr << "Something went wrong to open the file......"<< endl ;
    }
    file.close();
}

double DataSetFrame::Prediction(){
    default_random_engine generator;
    normal_distribution<double> distribution(0.0,1.0);
    double sum_St, number, vol;

    int npaths = 10000;  // number of experiments
    vol = getVol() * sqrt(this->mat);

    double baseCal = S0->getPrice() * exp(this->Rf - 0.5 * vol * vol);
    for (int i = 0; i < npaths; ++i) {
        number = distribution(generator);
        // sum_St += baseCal * this->mat + vol * number * sqrt(this->mat);
        sum_St += baseCal + exp(vol * number);
    }

    if (contract->getCP()){
        return exp(-(this->Rf)*(this->mat)) *  max(sum_St / npaths - contract->getPrice(), 0.0);
    }else{
        return exp(-(this->Rf)*(this->mat)) *  max(0.0, contract->getPrice() - sum_St / npaths);
    }
}

double DataSetFrame::getMean(){// for stock price
    double sum = 0.0;
    for (int i = 0; i<= this->length ;++i){
        sum += stockList[i].getPrice();
    }
    this->mean = sum/(length);
    return this->mean;
}

double DataSetFrame::getMu(){// for return
    double sum = 0.0;
    for (int i = 1; i< this->length ;++i){
        sum += ((stockList[i-1].getPrice()/stockList[i].getPrice()) -1);
    }
    this->mu = sum/(length-1);
    return this->mu;
}

double DataSetFrame::getVol(){
    // getMu has to be runed before getVar
    double deviation = 0;
    double mu = getMu();
    for (int i = 1; i< this->length ;++i){
        deviation += pow(stockList[i-1].getPrice()/stockList[i].getPrice() -1 - mu, 2);
    }
    this->vol = sqrt(deviation/(this->length-1));
    return this->vol; 
}

int DataSetFrame::getLength(){return this->length;}

Stock DataSetFrame::getStock(int num){
    if(num <= this->length){
        return this->stockList[num];
    }else{
        cout << "Stock was out of range" << endl;
        return Stock(Date(1,1,2000), 0);
    }
}

double DataSetFrame::getRf(){return this->Rf;}
void DataSetFrame::setRf(double num){this->Rf = num;}
int DataSetFrame::getMat(){return this->mat;}
Stock DataSetFrame::getS0(){return *this->S0;}
Contract DataSetFrame::getCon(){return *this->contract;}