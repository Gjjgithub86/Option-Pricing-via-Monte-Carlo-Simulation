


#include "DataSetFrame.h"
#include "Contract.h"
#include "Date.h"
#include "Stock.h"
#include "Entity_base.h"
#include <iostream>
#include <string>


void showResult(Contract *con, Stock *s){
    DataSetFrame df = DataSetFrame("AAPL.csv", con, s);
    cout << "The mean of Stock is " <<  df.getMean() << endl;
    cout << "the mean of return of the stock is " << df.getMu() * 100 << "%" << endl;
    cout <<"The Volatility is " << df.getVol() * 100 << "%" << endl;
    cout <<"the num of history data we used: " << df.getLength() << endl;
    cout << "The Rf is " << df.getRf() << endl;
    cout << "The Matturity is " << df.getMat() << endl;
    cout << endl;

    con->getCP()? cout << "This is a Call Option at strick price of " << df.getCon().getPrice() << endl:
                cout << "This is a Put Option at strick price of " << df.getCon().getPrice() << endl;
    cout << "With the S0: \n\tPrice: " << s->getPrice() << "\n\tBuyDate:"<< df.getS0().getDate().toString() << endl;
    cout << "The option with Monte Carlo Pricing is: ";
    cout << df.Prediction() << endl;
    cout << endl;
}

int main(){
    bool button = true;
    int choice;
    while (button){
        int con_mon, con_day, con_year, s_mon, s_day, s_year, cpe;
        bool cp;
        double k,p;

        cout << "Enter your Contract Information:" << endl;
        cout << "\tDate(in format of mm dd yyyy): ";
        cin >> con_mon >> con_day >> con_year;
        cout << "\tK: ";
        cin >> k;
        cout <<  "\tEnter 1 for call, 2 for put:";
        cin >> cpe;
        cp =(cpe == 2)? false: true;

        cout << "\n\nEnter your S0 Information:" << endl;
        cout << "\tDate(in format of mm dd yyyy): ";
        cin >> s_mon >> s_day >> s_year;

        if ((s_mon >= con_mon)&&(s_day>=con_day)&&(s_year>=con_year)){
            cout << "It is impossible that you buy a S0 before the option Contract!" << endl;
            cout << "Please reenter the information......" << endl;
            continue;
        }

        cout << "\tPrice: ";
        cin >> p;

        Contract *con = new Contract(Date(con_mon,con_day,con_year), (double)k, bool(cp));
        Stock *s = new Stock(Date(s_mon,s_day,s_year),(double)p);
        showResult(con, s);

        cout << "Do you want to quit the program? 1:quit , any integer else to continue calculation:" << endl;
        cin >> choice;
        if (choice == 1){
            button = false;
        }else {
            cout << "\n\nStart a new Calculation:";
        }
    }



    // the first test for the whole project
    //Contract *concall = new Contract(Date(12,31,2022), 110);
    //Stock *s = new Stock(Date(11,21,2022),130);
    //showResult(concall, s);
    //Contract *conput = new Contract(Date(12,31,2022), 110, false);
    //showResult(conput, s);

    return 0;
}

