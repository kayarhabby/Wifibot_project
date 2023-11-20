//
// Created by kaya on 06/11/23.
//

#ifndef PROJET_WIFIBOT_ORDER_H
#define PROJET_WIFIBOT_ORDER_H

#define SPEED_MAX_WITH_CTL 40
#define SPEED_MAX_WITHOUT_CTL 60


class Order {
private:
    short m_order_L ;
    short m_order_R ;
    bool m_speed_ctr ;
public:
    /**
     * constructeur de la classe Wifibot
     * @param left
     * @param right
     * @param ctr
     */
    Order(short left = 0, short right = 0, bool ctr = true);

    /**
     * permet de récupérer la valeur de la vitèsse sur la roue gauche
     * @return
     */
    short get_order_L() const;

    /**
     * permet de récupérer la valeur de la vitèsse sur la roue droite
     * @return
     */
    short get_order_R() const;

    /**
     * permet de recupérer la valeur du controle de vitèsse
     * @return
     */
    bool get_speed_ctr() const;

    /**
     * permet d'imposer les vitèsses sur les deux roues (gauche et droite)
     * @param left
     * @param right
     */
    void set_Order(short left, short right);

    /**
     * permet d'imposer la valeur du controle de vitèsse
     * @param ctr
     */
    void set_speed_ctr(bool ctr);

private:
    /**
     * limite les vitèsses prises sur les roues en fonction de la valeur du controle de vitèsse
     * [-60,60] si ctr = false
     * [-40,40] si ctr = true
     */
    void limit();


};


#endif //PROJET_WIFIBOT_ORDER_H
