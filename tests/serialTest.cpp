#include "../serialComm/serialComm.h"
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <stdio.h>

#define serialPort "/dev/ttyUSB0"

using namespace std;
using namespace std::chrono;

int main(){
  
  Serial serial("/dev/ttyUSB0", 115200);

  while(1){
    
    // auto start = high_resolution_clock::now();
    //serial.getJson();
    /*
    if(serial.newData){
      cout << "X: " << serial.xPos << " || Y: " << serial.yPos << endl;
      serial.newData = false;

      auto stop = high_resolution_clock::now();    
      auto duration = duration_cast<microseconds>(stop - start);
 
      cout << "Time between cycles: " << duration.count()/1000 << "ms" << endl;
    }*/

    serial.sendJson("{\"servo1\"10\"}");
    sleep(1);

  }

  /*

    serialib serial;
    // Connection to serial port
    char errorOpening = serial.openDevice(serialPort, 115200);


    // If connection fails, return the error code otherwise, display a success message
    if (errorOpening!=1) return errorOpening; 
    printf ("Successful connection to %s\n", serialPort);

    // Create the string
    char buffer[15] = "apple\n";
    
    // Write the string on the serial device
    serial.writeString(buffer);
    printf ("String sent: %s", buffer);

    // Read the string
    serial.readString(buffer, '\n', 14, 2000);
    printf("String read: %s\n", buffer);

    // Close the serial device
    serial.closeDevice();
    */
    return 0;
}
