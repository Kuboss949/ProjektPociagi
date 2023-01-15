//
// Created by creaz on 12.01.2023.
//

#include "Database.h"

template <typename T>
void enterAndValidate(T &value){
    do{
        cin >> value;
        if(value<0){
            cout << "Entered invalid data, try again" << endl;
        }
    }while(value<0);
}


Database::Database() {
    fileName="";
}

Database::Database(const string &fileName):fileName(fileName) {

}


void Database::loadRecords() {
    Entry tmp;
    reading.open(fileName);
    if(!reading.good()){
        cout << "Problem with file access!" << endl;
        return;
    }
    while(reading.eof()){
        tmp.readFromBinFile(reading);
        data.push_back(tmp);
    }
    reading.close();
}

void Database::createEntry() {
    string tmp, fromWhere, destination, trainName, trainOwner;
    DateAndTime arrival, departure;
    Train *entryTrain;
    Entry *newEntry;
    int platformNo, trainType;
    bool validResult;
    double maxVelocity;


    do {
        cout << "Please enter arrival date in DD-MM-YYYY format: " << endl;
        cin >> tmp;
        if(!(validResult=validateDate(tmp, arrival)))
            cout << "Data entered in wrong format, try again:" << endl;
    }while(!validResult);

    do {
        cout << "Please enter arrival time in HH:MM 24H format: " << endl;
        cin >> tmp;
        if(!(validResult=validateHour(tmp, arrival)))
            cout << "Data entered in wrong format, try again:" << endl;
    }while(!validResult);

    do {
        cout << "Please enter departure date in DD-MM-YYYY format (if it's the same as arrival, press enter): " << endl;
        cin.ignore();
        getline(cin, tmp);
        if(!(validResult=(validateDate(tmp, departure) || tmp.length()==0)) )
            cout << "Data entered in wrong format, try again:" << endl;
    }while(!validResult);
    if(tmp.length()==0){
        departure=arrival;
    }

    do {
        cout << "Please enter departure time in HH:MM 24H format: " << endl;
        cin >> tmp;
        if(!(validResult=validateHour(tmp, departure)))
            cout << "Data entered in wrong format, try again:" << endl;
    }while(!validResult);


    cout << "Enter train destination: "<< endl;
    cin >> destination;
    cout << "Enter train point of departure: "<< endl;
    cin >> fromWhere;

    cout << "Enter platform number: " << endl;
    enterAndValidate(platformNo);


    cout << "Enter train type: " << endl << "1) Passenger Train" << endl << "2) Cargo Train" << endl;

    do{
        cin >> trainType;
        if(trainType!=1 && trainType!=2){
            cout << "Entered invalid option, try again" << endl;
        }
    }while(trainType!=1 && trainType!=2);



    cout << "Enter train name: "<< endl;
    cin >> trainName;
    cout << "Enter train owner: "<< endl;
    cin >> trainOwner;

    cout << "Enter train max velocity: "<< endl;
    enterAndValidate(maxVelocity);


    if(trainType==1){
        int PassNumber;
        int numOfTravelClasses;
        cout << "Enter the maximum number of passengers: "<< endl;
        enterAndValidate(PassNumber);

        cout << "Enter number of travel classes (max 3): "<< endl;
        do{
            cin >> numOfTravelClasses;
            if(numOfTravelClasses<0 || numOfTravelClasses>3){
                cout << "Entered invalid option, try again" << endl;
            }
        }while(numOfTravelClasses<0 || numOfTravelClasses>3);
        entryTrain = new PassengerTrain(trainName, trainOwner, maxVelocity, PassNumber, numOfTravelClasses);
    }else{
        string trainCargoType;
        int trainMaxCargoMass;

        cout << "Enter train cargo type: "<< endl;
        cin >> trainCargoType;

        cout << "Enter train maximum cargo mass in tons: "<< endl;
        enterAndValidate(trainMaxCargoMass);

        entryTrain=new CargoTrain(trainName, trainOwner, maxVelocity, trainCargoType, trainMaxCargoMass);
    }

    newEntry = new Entry(arrival, departure, fromWhere, destination, platformNo, entryTrain);
    data.push_back(*newEntry);
}

void Database::printRecords(int count) {

    cout << left << setw(16) << "ARRIVAL TIME" << left << setw(16) << "DEPARTURE TIME" << left << setw(20) << "DESTINATION" << left << setw(20) << "ORIGIN" << left << setw(2) << "PLATFORM NO" << left << setw(25) << "TRAIN ID" << endl;

    if(count==0){
        for(int i=0;i<data.size();i++)
            cout << data[i];
    }else{
        for(int i=0;i<count;i++){
            cout << data[i];
        }
    }

}

void Database::saveRecords() {
    writing.open(fileName, ofstream::trunc);
    if(!writing.good()){
        cout << "Opening file error! \n";
        return;
    }

    for(int i=0;i<data.size();i++){
        data[i].writeToBinFile(writing);
    }
    writing.close();
}

void Database::setFile(string value) {
    fileName=value;
}
