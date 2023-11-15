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
    Order(short left = 0, short right = 0, bool ctr = true);

    short get_order_L() const;

    short get_order_R() const;

    bool get_speed_ctr() const;

    void set_Order(short left, short right);

    void set_speed_ctr(bool ctr);

private:
    void limit();


};


#endif //PROJET_WIFIBOT_ORDER_H
