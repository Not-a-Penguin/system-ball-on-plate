#include "serialComm.h"
#include "rapidJson/stringbuffer.h"
#include "rapidJson/writer.h"
#include <cassert>
#include <cstring>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>


Serial::Serial(const char* port, int baudRate){

  char errorOpening = this->serialOperations.openDevice(port, baudRate);

  if (errorOpening !=1){
    printf("Error opening serial port %s with error code: %c", port, errorOpening);
    throw std::runtime_error("Error opening serial port.");
  }
  
  printf("Successful connection to %s\n", port);

};

Serial::~Serial(){};

int Serial::getJson(){
  
  char rc;
  
  string messageFromSerial;
  
  this->serialOperations.readChar(&rc);

  if(rc == '{'){
    messageFromSerial += rc;
    while(rc != '}'){
      this->serialOperations.readChar(&rc);
      messageFromSerial += rc;
    }
    this->newData = true;
  }
  
  if(this->newData){
    this->rawMessage = messageFromSerial;
    this->serialDoc = this->parseJson(messageFromSerial);
    // this->newData = false;
  }
 
  return 0;
};

Document Serial::parseJson(string& docFromSerial){
 
  // cout << "Received: " << docFromSerial << endl;
  Document jsonFromSerial;
 
  try{
    //jsonFromSerial.Parse(docFromSerial);
    jsonFromSerial.Parse(docFromSerial.c_str());
    
  }
  catch (int error) {
    throw runtime_error("Failed to parse String into Json.");
  }

  try{
    assert(jsonFromSerial.IsObject());
  }
  catch(int error){
    throw runtime_error("Json assertion failed.");
  }
  
  return jsonFromSerial;
}

int Serial::sendJson(vector<const char*> keys, vector<float> values){

  StringBuffer messageToSerial;
  Writer<StringBuffer>writer(messageToSerial);
 
  writer.StartObject();
  for(int i=0; i<keys.size(); i++){
    writer.Key(keys[i]);
    writer.Int(values[i]);
  }
  writer.EndObject();
  
  this->serialOperations.writeString(messageToSerial.GetString());
  // cout << "returning from sendJson" << endl;
  return 0;
  
};
