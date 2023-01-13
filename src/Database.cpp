//
// Created by creaz on 12.01.2023.
//

#include "Database.h"

Database::Database() {
    fileName="";
}

Database::Database(string fileName) {
    this->open(fileName);
}

void Database::open(string fileName) {
    reading.open(fileName);
    if(!reading.good()){
        cout << "Opening file error!";
    }
    writing.open(fileName);
    if(!writing.good()){
        cout << "Opening file error!";
    }
    writing.seekp( - 1, ios_base::end );
}

void Database::loadRecords(int count) {
    Entry tmp;
    if(count==0){
        while(reading.eof()){
            tmp.readFromBinFile(reading);
            data.push_back(tmp);
        }
        reading.seekg(0, ios::beg);
    }else{
        for(int i=0;i<count;i++){
            if(reading.eof()){
                cout << "Record count in the file is less than " << count << "!" << endl;
                reading.seekg(0, ios::beg);
                break;
            }
            tmp.readFromBinFile(reading);
            data.push_back(tmp);
        }
    }
}

void Database::createEntry() {
    string tmp;
    DateAndTime arrival;
    bool validResult;
    do {
        cout << "Please enter arrival date in DD-MM-YYYY format: ";
        cin >> tmp;
        if(!(validResult=validateDate(tmp, arrival)))
            cout << "Data entered in wrong format, try again:" << endl;
    }while(!validResult);

    do {
        cout << "Please enter arrival time in HH:MM 24H format: ";
        cin >> tmp;
        if(!(validResult=validateHour(tmp, arrival)))
            cout << "Data entered in wrong format, try again:" << endl;
    }while(!validResult);

}
