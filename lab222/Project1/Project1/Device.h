#pragma once
#include <iostream> 
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "HardDrive.h"

using namespace std;

class Device
{
public:
    string name;
    string brand;
    int yearOfProduction;
    HardDrive *hardDrive;

    Device(string n, string b, int y, string dV, string s, bool iC, int pU, string dT);

    void displayInfo();
    void updateDriver(string newVersion);
    void changeStatus(const string& newStatus);
    void changeStatus(bool isConnected);
    int calculatePowerUsage(int hours);
    void connect(HardDrive &driver);
    Device getDeviceInfo();
    void saveToFile();
    void readFromFile(ifstream& file);

private:
    string driverVersion;
    string status;
    bool isConnected;
    int powerUsage;
    string deviceType;
};

