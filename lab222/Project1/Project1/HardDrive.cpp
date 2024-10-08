#include "HardDrive.h"
#include"Device.h"
#include <iostream> 
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

HardDrive::HardDrive(int c, string b, string m, int rS, int wS, bool hS, string connT, int sR)
    : capacity(c), brand(b), model(m), readSpeed(rS), writeSpeed(wS),
    healthStatus(hS), connectionType(connT), spindleRotation(sR) {}

void HardDrive::displayInfo() {
    cout << "Brand: " << brand << endl;
    cout << "Model: " << model << endl;
    cout << "Capacity: " << capacity << "GB" << endl;
    cout << "Read Speed: " << readSpeed << "MB/s" << endl;
    cout << "Write Speed: " << writeSpeed << "MB/s" << endl;
    cout << "Health Status: " << (healthStatus ? "Good" : "Bad") << endl;
    cout << "Connection Type: " << connectionType << endl;
    cout << "Spindle Rotation: " << spindleRotation << "RPM" << endl;
}

void HardDrive::checkHealth() {
    healthStatus = (readSpeed > 50 && writeSpeed > 50);
}

void HardDrive::updateSpeed(int rS, int wS) {
    readSpeed = rS;
    writeSpeed = wS;
}

int HardDrive::totalSpeed() {
    return readSpeed + writeSpeed;
}

HardDrive HardDrive::getDriveInfo() {
    return *this;
}

string HardDrive::getConnectionType() {
    return connectionType;
}

void HardDrive::allocateRandomValues(int numValues) {
    int* values = new int[numValues];
    for (int i = 0; i < numValues; i++) {
        values[i] = readSpeed + rand() % 100;
    }
    sort(values, values + numValues);
    for (int i = 0; i < numValues; i++) {
        cout << values[i] << " ";
    }
    cout << endl;
    delete[] values;
}



void HardDrive::interactWithDevice(Device& device) {
    cout << "Interacting with device: " << device.name << endl;
    device.connect(*this);
}

void HardDrive::saveToFile(ofstream& file) {
    file << capacity << endl;
    file << readSpeed << endl;
    file << writeSpeed << endl;
    file << healthStatus << endl;
}

void HardDrive::readFromFile(ifstream& file) {
    file >> capacity;
    file >> readSpeed;
    file >> writeSpeed;
    file >> healthStatus;
    file.ignore();
}