#include "Wifibot.h"
#include <iostream>

using namespace std;

int main() {

    // Créez un objet Wifibot en utilisant l'objet Order
    Wifibot myWifibot;

    // Démarrez le robot avec une vitesse initiale
    myWifibot.speed_up();
    cout << "Robot en accélération." << endl;
    myWifibot.displayAttribut();

    // Effectuez une rotation vers la gauche
    myWifibot.turn(1);
    cout << "Rotation vers la gauche." << endl;
    myWifibot.displayAttribut();

    // Effectuez une rotation vers la droite
    myWifibot.turn(-1);
    cout << "Rotation vers la droite." << endl;
    myWifibot.displayAttribut();

    // Arrêtez le robot
    myWifibot.stop();
    cout << "Robot arrêté." << endl;
    myWifibot.displayAttribut();

    // Effectuez une rotation horaire
    myWifibot.rotate(1);
    cout << "Rotation horaire." << endl;
    myWifibot.displayAttribut();

    // Effectuez une rotation antihoraire
    myWifibot.rotate(-1);
    cout << "Rotation antihoraire." << endl;
    myWifibot.displayAttribut();

    // Réduisez la vitesse du robot
    myWifibot.speed_down();
    cout << "Réduction de vitesse." << endl;
    myWifibot.displayAttribut();

    return 0;
}
