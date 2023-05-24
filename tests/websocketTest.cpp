#include "../websocket/websocketServer.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <math.h>
#include <ostream>
#include <sstream>
#include <string>
#include <unistd.h>


void runServer(WsServer* server, int port){
  server->run(port);
}

int main (int argc, char *argv[]) {

  try {
    WsServer server_instance;

    // Start a thread to run the processing loop
    thread wsProcessThread(bind(&WsServer::process_messages,&server_instance));

    //Run asio loop in its own thread
    thread serverThread(bind(runServer, &server_instance, 1836));
    
    std::cout << "Websocket test" << std::endl;
    float i=0;
    std::stringstream ss;

    while(1){
      
      ss << "{\"x\":\"" << 10 * sin(i) << "\",\"y\":\"" << 10 * cos(i) << "\"}";
      server_instance.sendBroadcast(ss.str());
      std::stringstream().swap(ss);
      i += 0.1;
      sleep(1);

    }

    wsProcessThread.join(); 
    serverThread.join();

  } 

  catch (websocketpp::exception const & e) {
    std::cout << e.what() << std::endl;
  }

  catch(...){
    std::cout << "Exception" << std::endl;
  }

  return 0;
}
