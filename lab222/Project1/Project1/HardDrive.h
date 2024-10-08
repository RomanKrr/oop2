#pragma once
#include <iostream> 
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
//#include "Device.h"

using namespace std;

class Device;

class HardDrive
{
public:
    int capacity;
    string brand;
    string model;

    HardDrive(int c, string b, string m, int rS, int wS, bool hS, string connT, int sR);

    void displayInfo();
    void checkHealth();
    void updateSpeed(int rS, int wS);
    int totalSpeed();
    HardDrive getDriveInfo();
    string getConnectionType();
    void allocateRandomValues(int numValues);
    void interactWithDevice(Device& device);
    void saveToFile(ofstream& file);
    void readFromFile(ifstream& file);

private:
    int readSpeed;
    int writeSpeed;
    bool healthStatus;
    string connectionType;
    int spindleRotation;

};