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
      messageFromServer << serial.rawMessage;
      server_instance.sendBroadcast(messageFromServer.str()); 
      stringstream().swap(messageFromServer);

      cout << "X: " << serial.xPos << " || Y: " << serial.yPos << endl;

      auto stopGetData = high_resolution_clock::now();
      auto durationGetData = duration_cast<microseconds>(stopGetData - start);
      cout << "Time to acquire data: " << durationGetData.count()/1000 << "ms" << endl;
     
      //Insert controller here. Using the input from the serial
      //to create a control law to construct the desired output
      //
    
      int angle1 = 10;
      int angle2 = 22;
      int angle3 = 34;

      vector<const char*> keys;
      keys.push_back("Angle1");
      keys.push_back("Angle2");
      keys.push_back("Angle3");

      vector<int> values;
      values.push_back(angle1);
      values.push_back(angle2);
      values.push_back(angle3);

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
