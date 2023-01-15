#include <iostream>
#include <fstream>
#include "PassengerTrain.h"
#include "CargoTrain.h"
#include "DateAndTime.h"
#include "Entry.h"
#include "validation.h"
#include "Database.h"
using namespace std;

int main()
{
    Database d1("example1.txt");

    for(int i=0;i<4;i++)
        d1.createEntry();


    d1.printRecords();

    d1.saveRecords();


    /*CargoTrain t1;
    CargoTrain t2("H2K85XZ", "PKP", 130.4,"coal", 321);
    DateAndTime d1(7,4,2001,13,42);
    DateAndTime d2(3,4,2001,12,23);
    Train *t3=new PassengerTrain("ZXC2351", "Koleje Slaskie", 74.3, 100, 2);
    Entry e1(d1, d2, "Krakow", "Gdansk", 12, t3);
    Entry e2;


    cout << e1 << endl;
    //e1.getTrainInfo();

    ofstream fileBin{"data.txt", ios::binary};
    if(fileBin.good()){
        e1.writeToBinFile(fileBin);
    }
    fileBin.close();

    ifstream fileBin1{"data.txt", ios::binary};
    if(fileBin.good()){
        e2.readFromBinFile(fileBin1);
    }
    fileBin.close();
    cout << e2 << endl;
    //e2.getTrainInfo();*/




    return 0;

}

