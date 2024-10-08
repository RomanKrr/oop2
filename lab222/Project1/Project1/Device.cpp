#include "Device.h"
#include "HardDrive.h"
#include <iostream> 
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

Device::Device(string n, string b, int y, string dV, string s, bool iC, int pU, string dT)
 : name(n), brand(b), yearOfProduction(y), driverVersion(dV),
    status(s), isConnected(iC), powerUsage(pU), deviceType(dT) {}

void Device::displayInfo() {
    cout << "Device Name: " << name << endl;
    cout << "Brand: " << brand << endl;
    cout << "Year of Production: " << yearOfProduction << endl;
    cout << "Driver Version: " << driverVersion << endl;
    cout << "Status: " << status << endl;
    cout << "Connected: " << (isConnected ? "Yes" : "No") << endl;
    cout << "Power Usage: " << powerUsage << "W" << endl;
    cout << "Device Type: " << deviceType << endl;
}

void Device::updateDriver(string newVersion) {
    driverVersion = newVersion;
}

void Device::changeStatus(const string& newStatus) {
    status = newStatus;
}

void Device::changeStatus(bool isConnected) {
    //connect(isConnected);
}

int Device::calculatePowerUsage(int hours) {
    return powerUsage * hours;
}

void Device::connect(HardDrive& driver) {
    hardDrive = &driver;
    //isConnected = connect;
   // status = connect ? "Connected" : "Disconnected";
}

Device Device::getDeviceInfo() {
    return *this;
}

void Device::saveToFile() {
    ofstream file("device.txt");

    if (!file) {
        cerr << "Can`t open file" << endl;
        return;
    }
    file << name << endl;
    file << brand << endl;
    file << driverVersion << endl;
    file << status << endl;
    file << isConnected << endl;
    file << powerUsage << endl;
    file << deviceType << endl;
    file.close();
}

void Device::readFromFile(ifstream& file) {
    getline(file, name);
    getline(file, driverVersion);
    getline(file, status);
    file >> isConnected;
    file >> powerUsage;
    file.ignore();
}
