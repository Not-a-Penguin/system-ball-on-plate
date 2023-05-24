#include "serialComm.h"
#include <cassert>
#include <cstring>
#include <iostream>
#include <string>


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
    // cout << "string is: " << messageFromSerial << endl;
    this->parseCoordinates(messageFromSerial);
    // this->newData = false;
  }
 
  return 0;
};

int Serial::parseCoordinates(string& docFromSerial){
 
  // cout << "Received: " << docFromSerial << endl;
  Document jsonFromSerial;
 
  try{
    //jsonFromSerial.Parse(docFromSerial);
    jsonFromSerial.Parse(docFromSerial.c_str());

  }
  catch (int error) {
    throw runtime_error("Failed to parse String into Json.");
    return -1;
  }

  assert(jsonFromSerial.IsObject());

  //Assert whether or not the variables are present in the Json 
  //with the correct type

  if(jsonFromSerial.HasMember("xPos") == false){
    throw runtime_error("Json has no member 'xPos'");
    return -1;
  }

  if(jsonFromSerial.HasMember("yPos") == false){
    throw runtime_error("Json has no member 'yPos'");
    return -1;
  }
  
  
  if(jsonFromSerial["xPos"].IsNumber() && jsonFromSerial["yPos"].IsNumber()){
    this->xPos = jsonFromSerial["xPos"].GetInt();
    this->yPos = jsonFromSerial["yPos"].GetInt();

    return 0;
  }

  return -1;
      
}

int Serial::sendJson(){

  return 0;

};
