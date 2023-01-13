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
    Database(string fileName);


    void open(string fileName);

    void loadRecords(int count=0);

    void createEntry();








};



