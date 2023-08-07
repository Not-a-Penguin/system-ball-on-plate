#include "../serialComm/serialComm.h"
#include "../websocket/websocketServer.h"
#include "../systemIdentification/mimoIdentification.h"
#include <bits/chrono.h>
#include <chrono>
#include <iostream>
#include <thread>

Serial serial("/dev/ttyUSB0", 115200);
WsServer serverInstance;
MimoIdentification mimoSysId;

int main(){
  
  thread wsProcessThread(bind(&WsServer::process_messages, &serverInstance));
  thread serverThread(bind(WsServer::runServer, &serverInstance, 1836));
  std::cout << "Websocket server started" << std::endl; 
  

  while(1){
    auto start = chrono::high_resolution_clock::now();

    //Get data from serial if if it's avaliable
    serial.getJson();
    if(serial.newData){
      
     // Providing a seed value
	    srand((unsigned) time(NULL));

	// Get a random number
	    int random = rand();

	// Print the random number
	    cout<<random<<endl; 

      //serverInstance.sendBroadcast(serial.rawMessage.c_str()); 
      
      //Declare variables for everything you expect from the Json object
      float xPos = serial.serialDoc["xPos"].GetFloat();
      int yPos = serial.serialDoc["yPos"].GetInt();
      float xAngle = serial.serialDoc["xAngle"].GetFloat();
      float yAngle = serial.serialDoc["yAngle"].GetFloat();

      cout << "X angle = " << xAngle << " || Y angle = " << yAngle << endl;
      // auto stopGetData = chrono::high_resolution_clock::now();

      // auto durationGetData = chrono::duration_cast<chrono::microseconds>(stopGetData - start);

      vector<float> outputs = {10, 120, 120};//mimoSysId.identifyMimo({xAngle, yAngle});
      
      serial.sendJson({"servo1", "servo2", "servo3"}, outputs);

      // auto stopProcessingData = chrono::high_resolution_clock::now();
      // auto durationProcessingData = chrono::duration_cast<chrono::microseconds>(stopProcessingData - start);
      serial.newData = false;
    }


  }
  
  wsProcessThread.join();
  serverThread.join();
  return 0;
}
