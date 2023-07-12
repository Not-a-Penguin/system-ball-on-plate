#ifndef WEBSOCKETSERVER_H
#define WEBSOCKETSERVER_H

#include <string>
#include <websocketpp/config/asio_no_tls.hpp> //Requires Boost
#include <websocketpp/server.hpp>
#include <websocketpp/common/thread.hpp>
#include <iostream>
#include <set>

typedef websocketpp::server<websocketpp::config::asio> server;

using websocketpp::connection_hdl;
using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

using websocketpp::lib::thread;
using websocketpp::lib::mutex;
using websocketpp::lib::lock_guard;
using websocketpp::lib::unique_lock;
using websocketpp::lib::condition_variable;

/* on_open insert connection_hdl into channel
 * on_close remove connection_hdl from channel
 * on_message queue send to all channels
 */

enum action_type {
    SUBSCRIBE,
    UNSUBSCRIBE,
    MESSAGE
};


struct action {
    action(action_type t, connection_hdl h) : type(t), hdl(h) {}
    action(action_type t, connection_hdl h, server::message_ptr m)
      : type(t), hdl(h), msg(m) {}

    action_type type;
    websocketpp::connection_hdl hdl;
    server::message_ptr msg;
};

class WsServer{

  public:
    
    WsServer();
    ~WsServer();
    void run(uint16_t port);
    void on_open(connection_hdl hdl);
    void on_close(connection_hdl hdl);
    void on_message(connection_hdl hdl, server::message_ptr msg);
    void process_messages();

    void sendBroadcast(std::string msg);
    server m_server;

    static void runServer(WsServer* server, int port);

  private:

    typedef std::set<connection_hdl,std::owner_less<connection_hdl> > con_list;

    con_list m_connections;
    std::queue<action> m_actions;

    mutex m_action_lock;
    mutex m_connection_lock;
    condition_variable m_action_cond; 
};

#endif // !DEBUG
