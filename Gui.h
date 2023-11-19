//
// Created by kaya on 18/11/23.
//

#ifndef PROJET_WIFIBOT_GUI_H
#define PROJET_WIFIBOT_GUI_H
#include <gtkmm.h>
//#include <gtkmm/main.h>
//#include <gtkmm/window.h>
//#include <gtkmm/button.h>
#include <iostream>
#include "Wifibot.h"

class Gui : public Gtk::Window { // La classe Gui hérite de la classe Gtk::Window
public:
    Gui(); // Constructeur
    ~Gui(); // Destructeur
    void configureButton(Gtk::Button& button, const std::string& filename, Gtk::Image& image);
    void configureImage(const std::string& filename, Gtk::Image& image);

protected:

    //Child widgets:
    Gtk::Frame m_Frame1;
    Gtk::Frame m_Frame2;
    Gtk::Frame m_Frame3;
    Gtk::VBox vbox;
    Gtk::HBox hbox1;
    Gtk::HBox hbox2;

    Gtk::Image m_image;
    Gtk::Image m_image1;
    Gtk::Image m_image2;
    Gtk::Image m_image3;
    Gtk::Image m_image4;
    Gtk::Image m_image5;
    Gtk::Image m_image6;

    Gtk::Button button_up_arrow;
    Gtk::Button button_left_arrow;
    Gtk::Button button_right_arrow;
    Gtk::Button button_down_arrow;
    Gtk::Button button_spin_left_arrow;
    Gtk::Button button_spin_right_arrow;
    // Grille de boutons
    Gtk::Grid grid;
    Gtk::VScale m_speedSlider;
private:
    Gtk::Button m_button_stop; // Déclaration de l’objet membre m_button_1 du type Gtk::Button
    Gtk::Entry m_entry;
    Gtk::Button m_button_connexion;
    Wifibot m_robot;


};


#endif //PROJET_WIFIBOT_GUI_H
