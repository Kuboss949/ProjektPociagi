#pragma once
#include <vector>
#include "Entry.h"
#include "validation.h"

using namespace std;

class Database {
    vector<Entry> data;
    string fileName;
    ifstream reading;
    ofstream writing;
public:
    Database();
    Database(const string &fileName);

    void loadRecords();
    void saveRecords();
    void setFile(string value);

    void printRecords(int count=0);

    void createEntry();

};




