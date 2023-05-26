#ifndef SERIALCOMM_H
#define SERIALCOMM_H

#include "serialib.h"
#include "rapidJson/document.h"
#include <stdexcept>
#include <iostream>

using namespace rapidjson;
using namespace std;

class Serial{
  
  private:

    serialib serialOperations;
  
  public:
  
    Serial(const char* port, int baudRate);
    ~Serial();

    int getJson();
    int sendJson();    
  
    bool newData = false;

    string rawMessage;
  //Specific to ball on plate, parse json looking for x and y coordinates
  //and pass them to class atributes
    int parseCoordinates(string& jsonFromSerial);

    float xPos;
    float yPos;

    

};

#endif // !JSONLIB_H
