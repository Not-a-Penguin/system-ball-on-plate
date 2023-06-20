#ifndef SERIALCOMM_H
#define SERIALCOMM_H

#include "serialib.h"
#include "rapidJson/document.h"
#include "rapidJson/writer.h"
#include "rapidJson/stringbuffer.h"
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
  
    bool newData = false;

    string rawMessage;


  //Specific to ball on plate, parse json looking for x and y coordinates
  //and pass them to class atributes
  //sendJson is set to send 3 ints. Change for whatever you need to send
    
    template<typename Key, typename Value, typename... Args>
    int sendJson(Key key, Value value, Args... args);

    int sendJson(void);    
    int parseCoordinates(string& jsonFromSerial);
    float xPos;
    float yPos;

    

};

#endif // !JSONLIB_H
