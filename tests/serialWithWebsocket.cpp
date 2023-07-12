#include "../websocket/websocketServer.h"
#include "../serialComm/serialComm.h"
#include <chrono>
#include <functional>
#include <iostream>
#include <sstream>
#include <thread>
#include <vector>
#include <websocketpp/error.hpp>

using namespace std;
using namespace std::chrono;
void runServer(WsServer* server, int port){
  server->run(port);
}

int main(){

  stringstream messageFromServer;
  WsServer server_instance;

  thread wsProcessThread(bind(&WsServer::process_messages, &server_instance));
  thread serverThread(bind(runServer, &server_instance, 1836));
  
  cout << "Websocket server started" << endl;

  Serial serial("/dev/ttyUSB0", 115200);

  
  while(1){
    
    auto start = high_resolution_clock::now();
    
    serial.getJson();
    if(serial.newData){
      
      serial.newData = false;

      //Send raw json string through websocket
      messageFromServer << serial.rawMessage;   
      server_instance.sendBroadcast(messageFromServer.str()); 
      stringstream().swap(messageFromServer);

      //Now would be a good time to declare a variable for everything you
      //might wanna get from the json object
      int xPos = serial.serialDoc["xPos"].GetInt();
      int yPos = serial.serialDoc["yPos"].GetInt();
      float xAngle = serial.serialDoc["xAngle"].GetFloat();
      float yAngle = serial.serialDoc["yAngle"].GetFloat();

      
      //cout << "X: " << xPos << " || Y: " << yPos << endl;

      auto stopGetData = high_resolution_clock::now();
      auto durationGetData = duration_cast<microseconds>(stopGetData - start);
      //cout << "Time to acquire data: " << durationGetData.count()/1000 << "ms" << endl;
     
      //Insert controller here. Using the input from the serial
      //to create a control law to construct the desired output
      //
    
      float angle1 = 10;
      float angle2 = 22;
      float angle3 = 34;

      vector<const char*> keys = {"Angle1", "Angle2", "Angle3"};
      vector<float> values = {angle1, angle2, angle3};
      
      //Send json. The arguments are in pairs of key and value
      //The method accepts any size as long as each key have its value.
      serial.sendJson(keys, values);

      auto stopProcessData = high_resolution_clock::now();
      auto durationProcessData = duration_cast<microseconds>(stopProcessData - start);
      cout << "Time to process data: " << durationProcessData.count()/1000 << "ms" << endl;
    }
  }

  
  wsProcessThread.join();
  serverThread.join();
  return 0;
}
