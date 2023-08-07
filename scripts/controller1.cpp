#include <chrono>
#include <cmath>
#include <iostream>
#include <thread>
#include <vector>

#include "../serialComm/serialComm.h"

Serial serial("/dev/ttyUSB0", 115200);

int main(){

  using namespace std;

  float i = 0;
  float amplitude = 20;

  while(1){

    auto start = chrono::high_resolution_clock::now();

    serial.getJson();
    if(serial.newData){

      float xPos = serial.serialDoc["xPos"].GetFloat();
      float yPos = serial.serialDoc["yPos"].GetFloat();
  
      cout << "Xpos = " << xPos << " / Ypos = " << yPos << endl;
        
      
      // float angle1 = 120;
      // float angle2 = 80;
      // float angle3 = 100;

      float angle1 = 128 + amplitude*sin(i);
      float angle2 = 130 + amplitude*sin(i + 120);
      float angle3 = 130 + amplitude*sin(i + 240);

      i = i + 0.2;
      if(i >90){i = 0;}
      
      // cout << "Teste = " << teste << endl;

      vector<float> outputs = {angle1, angle2, angle3};
      serial.sendJson({"servo1", "servo2", "servo3"}, outputs);

      serial.newData = false;
    }
  }

  return 0;
}
