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
    /**
     * Construteur de la classe Wifibot
     */
    Wifibot();

    /**
     * destructeur de la classe Wifibot
     */
    ~Wifibot();

    /**
     * Méthode permettant d'arrêter le robot
     */
    void stop();

    /**
     * Permet de faire avancer le robot vers l'avant
     */
    void speed_up();

    /**
     * permet de faire reculer le robot vers l'arrière
     */
    void speed_down();

    /**
     * Permet de faire pivoter le robot dans une direction ou une autre selon la direction
     * si direction vaut +1 virage à droite
     * si direction vaut -1 virage à gauche
     * @param direction
     */
    void turn(int direction);

    /**
     * permet de faire tourner le robot sur lui dans une direction ou une autre
     * si direction vaut 1 sens horaire
     * si derction vaut -1 sens trigonométrique
     * @param direction
     */
    void rotate (int direction) ;

    /**
     * Permet d'afficher les attributs de l'objet Order
     */
    void displayAttribut();

    /**
     * assure la connexion réseaux entre le serveur local et le robot et la mise en marche du programme
     * @param ip adresse ip du serveur local
     */
    void connect(std::string ip);

    /**
     * destruction du socket et de l'objet wifibot
     */
    void disconnect();

    /**
     * calcule le crc de la trame
     * @param trame trame
     * @param length longueur de la trame
     * @return valeur du crc
     */
    unsigned short crc16(const char* trame, unsigned short length);

    /**
     * permet d'imposer une certaine vitèsse au roue
     * @param speed
     */
    void setSpeed(short speed);



private:
    /**
     * démarre le thread
     */
    void run();
};


#endif //PROJET_WIFIBOT_WIFIBOT_H
