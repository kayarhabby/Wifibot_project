//
// Created by kaya on 06/11/23.
//

#include "Wifibot.h"
using namespace std;

Wifibot::Wifibot() :
        m_order(0, 0, true),
        m_stop(false),
        m_p_thread(nullptr),
        m_socket() {
    // Additional constructor logic, if needed
}

void Wifibot::speed_up(){
    m_order.set_Order(m_order.get_order_L() + 5 ,m_order.get_order_R() + 5 );
}
void Wifibot::speed_down(){
    m_order.set_Order(m_order.get_order_L() - 5,m_order.get_order_R() - 5);
}
void Wifibot::turn(int direction) {
    // Obtenir les ordres gauche et droit
    short left = m_order.get_order_L();
    short right = m_order.get_order_R();

    // Calculer la consigne pour les deux moteurs (20% des ordres)
    short consigne_L = 0.2 * left;
    short consigne_R = 0.2 * right;

    if (direction == 1) {
        // Tourner vers la gauche en augmentant la consigne du moteur gauche
        m_order.set_Order(left + consigne_L, right - consigne_R);
    } else if (direction == -1) {
        // Tourner vers la droite en diminuant la consigne du moteur gauche
        m_order.set_Order(left - consigne_L, right + consigne_R);
    }

    /**
     *  faire la moyenne des deux vitèsses et les données aux roues après turn
     *  reste à implémenter
     */

    int moy_vitesse =  (m_order.get_order_R() + m_order.get_order_L()) / 2;

    m_order.set_Order(moy_vitesse, moy_vitesse);
}

void Wifibot::rotate (int direction){
    //temporisation d'une seconde
    usleep(1000);

    if (direction == 1) {
        // Tourner dans le sens horaire
        m_order.set_Order(-10, 10);
    } else if (direction == -1) {
        // Tourner le sens trigonométrique
        m_order.set_Order(10, -10);
    }

}

void Wifibot::displayAttribut() {

    cout << "vitèsse roue gauche : " << m_order.get_order_L() << endl;

    cout << "vitèsse roue droite : " << m_order.get_order_R() << endl;

    if(m_order.get_speed_ctr())
        cout << "contôle de vitèsse : " << "true" << endl;
    else
        cout << "contôle de vitèsse : " << "false" << endl;
}

void Wifibot::run() {
    static int cpt;
    while(!m_stop) {
        std::cout << "Thread [send] : " << ++cpt << std::endl;
//
// Code de l’émission de la trame
//
        m_socket.send("Hello World !");
        std::this_thread::sleep_for(std::chrono::milliseconds(LOOP_TIME));
    }
// #define LOOP_TIME 200 dans wifibot.h
    std::cout << "Thread [send] : stop!" << std::endl << std::endl;
}

void Wifibot::start() {
    m_p_thread = new std::thread([this]() { run(); });
}

void Wifibot::stop() {
    if (m_p_thread && m_p_thread->joinable()) {
        m_stop = true;
        m_p_thread->join();
        delete m_p_thread;  // Libérez la mémoire allouée pour le thread
        m_p_thread = nullptr;
    }
}

Wifibot::~Wifibot() {
    disconnect();
}

void Wifibot::connect(string ip) {
    // ouverture du socket avec comme Ip 127.0.0.1 et le port d’écoute.
    m_socket.open(ip,15020);
    if(m_socket.is_open()){
        start();
    }
}

void Wifibot::disconnect() {
    stop();
    m_socket.close();
}
