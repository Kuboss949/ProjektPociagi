#include "Train.h"


Train::Train()
{
    name = "";
    owner = "";
    maxVelocity = 0.0;
}

Train::Train(string name, string owner, double maxVelocity):name(name),owner(owner),maxVelocity(maxVelocity)
{
}

void Train::print()
{
    cout << "Name: " << name << endl;
    cout << "Owner: " << owner << endl;
    cout << "Maximum velocity: " << maxVelocity << " km/h" << endl;
}

void Train::setName(string value)
{
    for (int i=0; i<value.length(); i++)
        toupper(value[i]);
    this->name = value;
}

string Train::getName()
{
    return this->name;
}

void Train::setOwner(string value)
{
    this->owner = value;
}

string Train::getOwner()
{
    return this->owner;
}

void Train::setMaxVelocity(double value)
{
    this->maxVelocity = value;
}

double Train::getMaxVelocity()
{
    return maxVelocity;
}

void Train::writeToBinFile(ofstream &stream) {
    if(stream.good()){
        int tmpSize = name.size();
        stream.write(reinterpret_cast<char*>(&tmpSize), sizeof(int));
        stream.write(&name[0], tmpSize);

        tmpSize = owner.size();
        stream.write(reinterpret_cast<char*>(&tmpSize), sizeof(int));
        stream.write(&owner[0], tmpSize);

        stream.write(reinterpret_cast<char*>(&maxVelocity), sizeof(maxVelocity));
    }
}

void Train::readFromBinFile(ifstream &stream) {
    int tmpSize;
    if(stream.good()){
        stream.read(reinterpret_cast<char*>(&tmpSize), sizeof(int));
        name.resize(tmpSize);
        stream.read(&name[0], tmpSize);

        stream.read(reinterpret_cast<char*>(&tmpSize), sizeof(int));
        owner.resize(tmpSize);
        stream.read(&owner[0], tmpSize);

        stream.read(reinterpret_cast<char*>(&maxVelocity), sizeof(maxVelocity));
    }
}


