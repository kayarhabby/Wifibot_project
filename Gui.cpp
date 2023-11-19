//
// Created by kaya on 18/11/23.
//

#include "Gui.h"

Gui::Gui() : m_button_stop("STOP"), m_entry(), m_button_connexion("Connexion"), m_robot()

{
    // Positionnement et redimensionnement de la fenêtre principale
    this->set_title("Wifibot");
    this->set_position(Gtk::WIN_POS_CENTER);
    this->set_border_width(10);

    // Frame 1: Text entry and connection button
    m_Frame1.set_label("Connexion");
    hbox1.set_homogeneous(true);

    m_entry.set_max_length(50);
    m_entry.set_placeholder_text("Type here");
    hbox1.pack_start(m_entry, Gtk::PACK_EXPAND_WIDGET);
    hbox1.pack_end(m_button_connexion, Gtk::PACK_EXPAND_WIDGET);

    m_Frame1.add(hbox1);
    vbox.pack_start(m_Frame1, Gtk::PACK_SHRINK);

    // Frame 3: Speed control
    m_Frame3.set_label("Speed Control");
    m_speedSlider.set_range(-40, 40); // Set the range according to your speed values
    m_speedSlider.set_inverted(true); // Adjust this if the direction of speed change is inverted
    m_speedSlider.set_value(0); // Set an initial value
    m_speedSlider.set_size_request(50, 200); // Adjust size as needed
    m_Frame3.add(m_speedSlider);
    vbox.pack_start(m_Frame3, Gtk::PACK_SHRINK);

    // Frame 2 : Image et grille de boutons
    m_Frame2.set_label("Control robot");
    configureImage("image/wifibot.png",m_image);

    // Boutons avec images
    configureButton(button_up_arrow, "image/up_arrow.png",m_image1);
    configureButton(button_left_arrow, "image/left_arrow.png",m_image2);
    configureButton(button_right_arrow, "image/right_arrow.png",m_image3);
    configureButton(button_down_arrow, "image/down_arrow.png",m_image4);
    configureButton(button_spin_left_arrow, "image/spin_left_arrow.png",m_image5);
    configureButton(button_spin_right_arrow, "image/spin_right_arrow.png",m_image6);

// Ajoutez les boutons à la grille

    grid.attach(m_image, 0, 0, 1, 4);  // Image
    grid.attach(button_up_arrow, 1, 0, 6, 1);  // Bouton 1
    grid.attach(button_left_arrow, 1, 1, 3, 1);  // Bouton 2
    grid.attach(button_right_arrow, 4, 1, 3, 1);  // Bouton 3
    grid.attach(button_down_arrow, 3, 2, 2, 1);  // Bouton 4
    grid.attach(button_spin_left_arrow, 1, 2, 2, 1);  // Bouton 5
    grid.attach(button_spin_right_arrow, 5, 2, 2, 1);  // Bouton 6
    grid.attach(m_button_stop, 1, 3, 6, 1);   // Bouton 7

    vbox.pack_end(grid, Gtk::PACK_EXPAND_WIDGET);

    m_Frame2.add(hbox2);
    vbox.pack_end(m_Frame2, Gtk::PACK_SHRINK);

    // Ajout du conteneur principal à la fenêtre
    this->add(vbox);

    // Affichage des widgets
    this->show_all();



    // Gestion de l’événement clique sur le bouton 1 (norme C++ 11)
    m_button_stop.signal_clicked().connect([this](){
        m_robot.stop();
        m_robot.displayAttribut();
    });

    // Gestion de l'événement clique sur le bouton de connexion
    m_button_connexion.signal_clicked().connect([this](){
        // Code du bouton de connexion
        std::string entry_text = m_entry.get_text();
        std::cout << "Connexion with: " << entry_text << std::endl;
        m_robot.connect(entry_text);
    });

    // Gestion de l'événement clique sur les boutons de directions
    button_up_arrow.signal_clicked().connect([this](){
        std::cout << "speed_up" << std::endl;
        m_robot.speed_up();
        m_robot.displayAttribut();
    });

    button_left_arrow.signal_clicked().connect([this](){
        std::cout << "turn left " << std::endl;
        m_robot.turn(1);
        m_robot.displayAttribut();
    });

    button_right_arrow.signal_clicked().connect([this](){
        std::cout << "turn right " << std::endl;
        m_robot.turn(-1);
        m_robot.displayAttribut();
    });

    button_down_arrow.signal_clicked().connect([this](){
        std::cout << "speed_down" << std::endl;
        m_robot.speed_down();
        m_robot.displayAttribut();
    });

    button_spin_left_arrow.signal_clicked().connect([this](){
        std::cout << "rotate left " << std::endl;
        m_robot.rotate(-1);
        m_robot.displayAttribut();
    });

    button_spin_right_arrow.signal_clicked().connect([this](){
        std::cout << "rotate right " << std::endl;
        m_robot.rotate(1);
        m_robot.displayAttribut();
    });

    // Connect the signal handler for value changes in the slider
    m_speedSlider.signal_value_changed().connect([this]() {
        // Code to update WifiBot speed based on slider value
        short speed = m_speedSlider.get_value();
        m_robot.setSpeed(speed); // Replace setSpeed with the actual method to update speed
        std::cout << "Speed changed to: " << speed << std::endl;
    });

}

void Gui::configureButton(Gtk::Button& button, const std::string& filename, Gtk::Image& image) {
    try {
        auto pixbuf = Gdk::Pixbuf::create_from_file(filename)->scale_simple(50, 50, Gdk::INTERP_BILINEAR);
        image.set(pixbuf);
        button.set_image(image);
    } catch (const Gdk::PixbufError& ex) {
        std::cerr << "Error loading image: " << ex.what() << std::endl;
    }
}

void Gui::configureImage(const std::string& filename, Gtk::Image& image) {
    try {
        auto pixbuf = Gdk::Pixbuf::create_from_file(filename);
        image.set(pixbuf);
    } catch (const Gdk::PixbufError& ex) {
        std::cerr << "Error loading image: " << ex.what() << std::endl;
    }
}

Gui::~Gui() {}