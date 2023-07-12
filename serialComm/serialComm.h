#ifndef SERIALCOMM_H
#define SERIALCOMM_H

#include "serialib.h"
#include "rapidJson/document.h"
#include "rapidJson/writer.h"
#include "rapidJson/stringbuffer.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>

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
    Document serialDoc;
   
    int sendJson(vector<const char*> keys, vector<float>values); 
    Document parseJson(string& jsonFromSerial);   

};

#endif // !JSONLIB_H
