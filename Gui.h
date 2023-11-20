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

private:
    Gtk::Button m_button_stop; // Déclaration de l’objet membre m_button_1 du type Gtk::Button
    Gtk::Button m_button_connexion;
    Wifibot m_robot;

protected:
    Gtk::Entry m_entry;

    //Child widgets:
    Gtk::Frame m_Frame1;
    Gtk::Frame m_Frame2;
    Gtk::Frame m_Frame3;
    Gtk::VBox vbox;
    Gtk::HBox hbox1;
    Gtk::HBox hbox2;

    Gtk::Button button_up_arrow;
    Gtk::Button button_left_arrow;
    Gtk::Button button_right_arrow;
    Gtk::Button button_down_arrow;
    Gtk::Button button_spin_left_arrow;
    Gtk::Button button_spin_right_arrow;
    Gtk::Image m_image;

    // Grille de boutons
    Gtk::Grid grid;
    Gtk::VScale m_speedSlider;

public:
    /**
     * constructeur de la classe Gui
     */
    Gui();
    /**
     * destructeur de la classe Gui
     */
    ~Gui();
    /**
     * permet de remplir les boutons avec les images de direction
     * @param button bouton
     * @param filename Nom de l'image
     */
    void configureButton(Gtk::Button& button, const std::string& filename);
    /**
     * permet d'initialiser l'image du wifibot
     * @param filename nom de l'image du wifibot
     * @return image initialisé
     */
    Gtk::Image configureImage(const std::string& filename);

};


#endif //PROJET_WIFIBOT_GUI_H
