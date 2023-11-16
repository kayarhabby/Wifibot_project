#include "Wifibot.h"
#include <gtkmm.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

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

    // Démarrez le robot avec une vitesse initiale
    myWifibot.speed_up();
    cout << "Robot en accélération." << endl;
    myWifibot.displayAttribut();

    // Démarrez le robot avec une vitesse initiale
    myWifibot.speed_up();
    cout << "Robot en accélération." << endl;
    myWifibot.displayAttribut();



//    // Démarrer le thread
//    myWifibot.start();
//
//
//    // thread part
//    for(int i=0; i<10; i++) {
//        std::cout << "Thread [main]" << std::endl;
//        std::this_thread::sleep_for(std::chrono::seconds(1));
//    }
//
//    // Arrêter le thread
//    myWifibot.stop();

    Gio::init();
    // Initialisation obligatoire des bibliothèques : Gio et Glib
    Glib::init(); // Inutile en lançant une interface graphique avec Gtk::Main et
    // Gtk::Window

    myWifibot.connect("127.0.0.1");
    for(int i=0; i<30; i++) {
        std::cout << "Thread [main]" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    myWifibot.disconnect();

    return 0;
}
