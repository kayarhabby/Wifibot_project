//
// Created by kaya on 06/11/23.
//

#ifndef PROJET_WIFIBOT_WIFIBOT_H
#define PROJET_WIFIBOT_WIFIBOT_H
#define LOOP_TIME 200

#include "Order.h"
#include "socket.h"
#include<unistd.h>
#include <iostream>
#include <thread>
const int POLYNOME = 0xA001;

class Wifibot {
private:
    Order m_order;
    std::thread* m_p_thread;
    bool m_stop;
    Socket_TCP m_socket;
public:
    Wifibot();
    ~Wifibot();

    void stop(); // Méthode pour arrêter le thread
    void speed_up();
    void speed_down();
    void turn(int direction);
    void rotate (int direction) ;

    void displayAttribut();
    void connect(std::string);
    void disconnect();
    unsigned short crc16(const char* trame, unsigned short length);

    void setSpeed(short speed);



private:
    void run();
};


#endif //PROJET_WIFIBOT_WIFIBOT_H
