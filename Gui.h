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

class Gui : public Gtk::Window { // La classe Gui hérite de la classe Gtk::Window
public:
    Gui(); // Constructeur
    ~Gui(); // Destructeur
protected:

    //Child widgets:
    Gtk::Frame m_Frame1;
    Gtk::Frame m_Frame2;
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

    Glib::RefPtr<Gdk::Pixbuf> m_pixbuf;
    Glib::RefPtr<Gdk::Pixbuf> m_pixbuf1;
    Glib::RefPtr<Gdk::Pixbuf> m_pixbuf2;
    Glib::RefPtr<Gdk::Pixbuf> m_pixbuf3;
    Glib::RefPtr<Gdk::Pixbuf> m_pixbuf4;
    Glib::RefPtr<Gdk::Pixbuf> m_pixbuf5;
    Glib::RefPtr<Gdk::Pixbuf> m_pixbuf6;

    Gtk::Button button_img1;
    Gtk::Button button_img2;
    Gtk::Button button_img3;
    Gtk::Button button_img4;
    Gtk::Button button_img5;
    Gtk::Button button_img6;
    // Grille de boutons
    Gtk::Grid grid;
private:
    Gtk::Button m_button_1; // Déclaration de l’objet membre m_button_1 du type Gtk::Button
    Gtk::Entry m_entry;
    Gtk::Button m_button_connexion;

};


#endif //PROJET_WIFIBOT_GUI_H
