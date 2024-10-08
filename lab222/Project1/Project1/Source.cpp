#include"Device.h"
#include"HardDrive.h"

#include <fstream>

int main() {

    Device device1("Monitor", "LG", 2020, "1.0", "Working", true, 30, "Display");
    Device device2("Mouse", "Logitech", 2019, "1.1", "Working", true, 5, "Input");
    Device device3("Keyboard", "Corsair", 2021, "1.2", "Working", true, 10, "Input");
    Device device4("Printer", "HP", 2018, "1.0", "Working", true, 15, "Output");
    Device device5("Webcam", "Logitech", 2022, "1.1", "Working", true, 20, "Input");

    Device* d1 = new Device("Speaker", "Bose", 2020, "1.0", "Working", true, 15, "Output");
    Device* d2 = new Device("Headset", "Sony", 2021, "1.1", "Working", true, 10, "Input");
    Device* d3 = new Device("Scanner", "Epson", 2019, "1.2", "Working", true, 10, "Input");
    Device* d4 = new Device("Microphone", "Shure", 2020, "1.0", "Working", true, 10, "Input");
    Device* d5 = new Device("Projector", "Epson", 2021, "1.1", "Working", true, 50, "Output");


    Device devicesStatic[5] = { device1, device2, device3, device4, device5 };
    Device* devicesDynamic[5] = { d1, d2, d3, d4, d5 };

    for (int i = 0; i < 5; i++) {
        devicesStatic[i].displayInfo();
        cout << endl;
    }

    for (int i = 0; i < 5; i++) {
        devicesDynamic[i]->displayInfo();
        cout << endl;
    }

    
    HardDrive hardDrive(1000, "Crucial", "MX500", 560, 510, true, "SATA III", 7200);
    hardDrive.displayInfo();
    hardDrive.checkHealth();
    hardDrive.updateSpeed(500, 322);
    hardDrive.totalSpeed();
    hardDrive.getConnectionType();

    hardDrive.allocateRandomValues(10);

    device1.saveToFile();

    for (int i = 0; i < 5; i++) {
        delete devicesDynamic[i];
    }

    return 0;
}