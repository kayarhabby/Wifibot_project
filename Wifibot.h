//
// Created by kaya on 06/11/23.
//

#ifndef PROJET_WIFIBOT_WIFIBOT_H
#define PROJET_WIFIBOT_WIFIBOT_H
#define LOOP_TIME 200

#include "Order.h"
#include<unistd.h>
#include <iostream>
#include <thread>

class Wifibot {
private:
    Order m_order;
    std::thread m_thread;
    bool m_stop;
public:
    Wifibot();

    void stop();
    void speed_up();
    void speed_down();
    void turn(int direction);
    void rotate (int direction) ;

    void displayAttribut();
    ~Wifibot();

private:
    void run();
};


#endif //PROJET_WIFIBOT_WIFIBOT_H
