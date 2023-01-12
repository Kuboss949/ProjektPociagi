//
// Created by creaz on 09.01.2023.
//

#include "Entry.h"


Entry::Entry(const DateAndTime &arrival, const DateAndTime &departure, const string &fromWhere,
             const string &destination, int platformNo, Train *entryTrain) : arrival(arrival), departure(departure),
                                                                        fromWhere(fromWhere), destination(destination),
                                                                        platformNo(platformNo), entryTrain(entryTrain) {}

Entry::Entry() {
    arrival=DateAndTime();
    departure=DateAndTime();
    fromWhere="";
    destination="";
    entryTrain=nullptr;
}

ostream &operator<<(ostream &lhs, const Entry &rhs) {
    lhs<< rhs.arrival << "\t" << rhs.departure << "\t" << rhs.destination << "\t" << rhs.fromWhere << "\t" << rhs.platformNo << "\t"<< rhs.entryTrain->getName();
    return lhs;
}

void Entry::writeToBinFile(ofstream &stream){
    arrival.writeToBinFile(stream);
    departure.writeToBinFile(stream);
    if(stream.good()){
        int tmpSize = destination.size();
        stream.write(reinterpret_cast<char*>(&tmpSize), sizeof(int));
        stream.write(&destination[0], tmpSize);

        tmpSize = fromWhere.size();
        stream.write(reinterpret_cast<char*>(&tmpSize), sizeof(int));
        stream.write(&fromWhere[0], tmpSize);

        stream.write(reinterpret_cast<char*>(&platformNo), sizeof(platformNo));
    }
    int type;
    if (CargoTrain* cargoTrain = dynamic_cast<CargoTrain*>(entryTrain)) {
        type=2;
    } else if (PassengerTrain* passengerTrain = dynamic_cast<PassengerTrain*>(entryTrain)) {
        type=1;
    } else {
        type=0;
    }
    stream.write(reinterpret_cast<char*>(&type), sizeof(int));
    entryTrain->writeToBinFile(stream);
}

void Entry::readFromBinFile(ifstream &stream) {
    int tmpSize;
    arrival.readFromBinFile(stream);
    departure.readFromBinFile(stream);
    if(stream.good()){
        stream.read(reinterpret_cast<char*>(&tmpSize), sizeof(int));
        destination.resize(tmpSize);
        stream.read(&destination[0], tmpSize);

        stream.read(reinterpret_cast<char*>(&tmpSize), sizeof(int));
        fromWhere.resize(tmpSize);
        stream.read(&fromWhere[0], tmpSize);

        stream.read(reinterpret_cast<char*>(&platformNo), sizeof(platformNo));
    }
    int type;
    stream.read(reinterpret_cast<char*>(&type), sizeof(int));
    if(entryTrain!= nullptr)
        delete entryTrain;
    if(type==0){
        entryTrain=new Train();
    }else if(type==1){
        entryTrain=new PassengerTrain();
    }else {
        entryTrain = new CargoTrain();
    }
    entryTrain->readFromBinFile(stream);
}

void Entry::getTrainInfo() {
    entryTrain->print();
}
