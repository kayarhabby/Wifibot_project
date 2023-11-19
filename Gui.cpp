//
// Created by kaya on 18/11/23.
//

#include "Gui.h"

Gui::Gui() : m_button_1("STOP"), m_entry(), m_button_connexion("Connexion")

{
    // Positionnement et redimensionnement de la fenêtre principale
    this->set_title("Wifibot");
    this->set_position(Gtk::WIN_POS_CENTER);
    this->set_border_width(10);

   // Frame 1 : Champ de saisie et bouton de connexion
    m_Frame1.set_label("Frame1 Widget");


   // Création de l'entrée sans initialisation de texte ici
    m_entry.set_max_length(50);
    m_entry.set_placeholder_text("Type here");  // Utilisation de placeholder_text au lieu de set_text
    hbox1.pack_start(m_entry);
    hbox1.pack_end(m_button_connexion);

    m_Frame1.add(hbox1);
    vbox.add(m_Frame1);

    // Frame 2 : Image et grille de boutons
    m_Frame2.set_label("Frame2 Widget");

    // Image (remplacez le chemin par le chemin réel de votre image)
    // Créez un objet Pixbuf à partir du fichier image

    // Chargez l'image à partir d'un fichier
    m_pixbuf = Gdk::Pixbuf::create_from_file("image/wifibot.png");
    // Définir l'image
    m_image.set(m_pixbuf);
//
//    hbox2.pack_start(m_image);

    // Boutons avec images

    // Ajoutez vos images aux boutons (remplacez le chemin par le chemin réel de vos images)
    // Création des Pixbuf avec des tailles spécifiques
    m_pixbuf1 = Gdk::Pixbuf::create_from_file("image/up_arrow.png")->scale_simple(50, 50, Gdk::INTERP_BILINEAR);
    m_image1.set(m_pixbuf1);
    button_img1.set_image(m_image1);

    m_pixbuf2 = Gdk::Pixbuf::create_from_file("image/left_arrow.png")->scale_simple(50, 50, Gdk::INTERP_BILINEAR);
    m_image2.set(m_pixbuf2);
    button_img2.set_image(m_image2);

    m_pixbuf3 = Gdk::Pixbuf::create_from_file("image/right_arrow.png")->scale_simple(50, 50, Gdk::INTERP_BILINEAR);
    m_image3.set(m_pixbuf3);
    button_img3.set_image(m_image3);

    m_pixbuf4 = Gdk::Pixbuf::create_from_file("image/down_arrow.png")->scale_simple(50, 50, Gdk::INTERP_BILINEAR);
    m_image4.set(m_pixbuf4);
    button_img4.set_image(m_image4);

    m_pixbuf5 = Gdk::Pixbuf::create_from_file("image/spin_left_arrow.png")->scale_simple(50, 50, Gdk::INTERP_BILINEAR);;
    m_image5.set(m_pixbuf5);
    button_img5.set_image(m_image5);

    m_pixbuf6 = Gdk::Pixbuf::create_from_file("image/spin_right_arrow.png")->scale_simple(50, 50, Gdk::INTERP_BILINEAR);;
    m_image6.set(m_pixbuf6);
    button_img6.set_image(m_image6);


// Ajoutez les boutons à la grille
// Ajout des boutons à la grille avec répartition équitable de l'espace restant

    grid.attach(m_image, 0, 0, 1, 4);  // Image
    grid.attach(button_img1, 1, 0, 3, 1);  // Bouton 1
    grid.attach(button_img2, 1, 1, 1, 1);  // Bouton 2
    grid.attach(button_img3, 2, 1, 2, 1);  // Bouton 3
    grid.attach(button_img4, 2, 2, 1, 1);  // Bouton 4
    grid.attach(button_img5, 1, 2, 1, 1);  // Bouton 5
    grid.attach(button_img6, 3, 2, 1, 1);  // Bouton 6
    grid.attach(m_button_1, 1, 3, 3, 1);   // Bouton 7

    hbox2.pack_start(grid);

    m_Frame2.add(hbox2);
    vbox.pack_end(m_Frame2);


    // Ajout du conteneur principal à la fenêtre
    this->add(vbox);

    // Affichage des widgets
    this->show_all();

//    // Gestion de l’événement clique sur le bouton 1 (norme C++ 11)
//    m_button_1.signal_clicked().connect([this](){
//        std::cout << "Hello World !" << std::endl;
//        // Code du bouton 1
//    });
//
//    // Gestion de l'événement clique sur le bouton de connexion
//    m_button_connexion.signal_clicked().connect([this](){
//        // Code du bouton de connexion
//        std::string entry_text = m_entry.get_text();
//        std::cout << "Connexion with: " << entry_text << std::endl;
//        // Ajoutez le code nécessaire pour gérer la connexion ici
//    });
}


Gui::~Gui() {}