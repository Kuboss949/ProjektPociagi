#pragma once
#include "DateAndTime.h"
#include "Train.h"
#include "CargoTrain.h"
#include "PassengerTrain.h"
#include <iomanip>

using namespace std;

class Entry {
    DateAndTime arrival;
    DateAndTime departure;
    string fromWhere;
    string destination;
    int platformNo;
    Train *entryTrain;
public:
    Entry();

    Entry(const DateAndTime &arrival, const DateAndTime &departure, const string &fromWhere, const string &destination,
          int platformNo, Train *entryTrain);

    friend ostream& operator<<(ostream &lhs, const Entry &rhs);

    void getTrainInfo();
    void writeToBinFile(ofstream &stream);
    void readFromBinFile(ifstream &stream);

};