#include "../websocket/websocketServer.h"
#include "../serialComm/serialComm.h"
#include <chrono>
#include <functional>
#include <iostream>
#include <sstream>
#include <thread>
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
      
      //Insert controller code here


    }

    auto stopProcessData = high_resolution_clock::now();
    auto durationProcessData = duration_cast<microseconds>(stopProcessData - start);
    cout << "Time to process data: " << durationProcessData.count()/1000 << "ms" << endl;
  }

  
  wsProcessThread.join();
  serverThread.join();
  return 0;
}
