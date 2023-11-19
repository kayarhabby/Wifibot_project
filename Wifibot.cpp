//
// Created by kaya on 06/11/23.
//

#include <netinet/in.h>
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
    static int cpt = 0;

    while (!m_stop) {
        char trame[9];

        char char1 = 0xFF;
        char char2 = 0x07;

        char char3 = m_order.get_order_L() & 0xFF;
        char char4 = (m_order.get_order_L() >> 8) & 0xFF;
        char char5 = m_order.get_order_R() & 0xFF;
        char char6 = (m_order.get_order_R() >> 8) & 0xFF;

        // Construct char7
        unsigned char char7 = 0;
        char7 |= (m_order.get_speed_ctr() ? (1 << 7) : 0);  // Left Side Closed Loop Speed control :: 1 -> ON
        char7 |= (m_order.get_order_L() ? (1 << 6) : 0);  // Left Side Forward :: 1 -> Forward
        char7 |= (m_order.get_speed_ctr() ? (1 << 5) : 0);  // Right Side Closed Loop Speed control :: 1 -> ON
        char7 |= (m_order.get_order_R() ? (1 << 4) : 0);  // Right Side Forward :: 1 -> Forward

        // Construct chars 8-9 (CRC16)
        trame[0] = char1;
        trame[1] = char2;
        trame[2] = char3;
        trame[3] = char4;
        trame[4] = char5;
        trame[5] = char6;
        trame[6] = char7;

        unsigned short crc16_value = crc16(trame, 7);  // CRC16 calculation on chars 1-7
        trame[7] = static_cast<char>(crc16_value & 0xFF);  // Low byte
        trame[8] = static_cast<char>((crc16_value >> 8) & 0xFF);  // High byte

        cout << "Thread [send] : " << ++cpt << endl;
        // Code d'émission de la trame
        cout << "char1 " << static_cast<int> (char1)<< endl;
        cout << "char2 " << static_cast<int>(char2) << endl;
        cout << "char3 " << static_cast<int>(char3) << endl;
        cout << "char4 " << static_cast<int>(char4) << endl;
        cout << "char5 " << static_cast<int>(char5) << endl;
        cout << "char6 " << static_cast<int>(char6) << endl;
        cout << "char7 " << static_cast<int>(char7) << endl;
        cout << "crc16 " << crc16_value << endl;
        m_socket.send(trame,9);
        //m_socket.send("Hello World!");
        this_thread::sleep_for(chrono::milliseconds(LOOP_TIME));
    }

    std::cout << "Thread [send] : stop!" << std::endl << std::endl;
}



// crc16

unsigned short Wifibot::crc16(const char* trame, unsigned short length) {
    unsigned short crc = 0xFFFF;

    for (unsigned short k = 0; k < length; k++) {
        char octet = trame[k];
        crc ^= octet;

        for (int i = 0; i < 8; ++i) {
            if (crc & 1)
                crc = (crc >> 1) ^ POLYNOME;
            else
                crc >>= 1;
        }
    }

    return crc;
}

void Wifibot::stop() {
  m_order.set_Order(0,0);
}

Wifibot::~Wifibot() {
    disconnect();
}

void Wifibot::connect(string ip) {
    // ouverture du socket avec comme Ip 127.0.0.1 et le port d’écoute.
    m_socket.open(ip,15020);
    if(m_socket.is_open()){
        m_p_thread = new std::thread([this](){ run(); });
    }
}

void Wifibot::disconnect() {
    if (m_p_thread && m_p_thread->joinable()) {
        m_stop = true;
        m_p_thread->join();
        delete m_p_thread;  // Libérez la mémoire allouée pour le thread
        m_p_thread = nullptr;
    }
    m_socket.close();
}

