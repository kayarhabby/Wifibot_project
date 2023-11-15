//
// Created by kaya on 06/11/23.
//

#include "Order.h"

Order::Order(short left, short right, bool ctr) : m_order_L(left), m_order_R(right),
                                                             m_speed_ctr(ctr) {limit();}

short Order::get_order_L() const {
    return m_order_L;
}

short Order::get_order_R() const {
    return m_order_R;
}

bool Order::get_speed_ctr() const {
    return m_speed_ctr;
}

void Order::set_Order(short left, short right) {
    m_order_L = left;
    m_order_R = right;
    limit();
}

void Order::set_speed_ctr(bool ctr) {
    m_speed_ctr = ctr;
    limit();

}

void Order::limit() {
    if(m_speed_ctr){
        if(m_order_R < - SPEED_MAX_WITH_CTL ) {
            m_order_R = - SPEED_MAX_WITH_CTL;
        }
        else if(m_order_R > SPEED_MAX_WITH_CTL){
            m_order_R = SPEED_MAX_WITH_CTL;
        }
        if(m_order_L < - SPEED_MAX_WITH_CTL){
            m_order_L = - SPEED_MAX_WITH_CTL;
        }
        else if(m_order_L > SPEED_MAX_WITH_CTL){
            m_order_L = SPEED_MAX_WITH_CTL;
        }

    }else{

        if(m_order_R < - SPEED_MAX_WITHOUT_CTL ) {
            m_order_R = - SPEED_MAX_WITHOUT_CTL;
        }
        else if(m_order_R > SPEED_MAX_WITHOUT_CTL){
            m_order_R = SPEED_MAX_WITHOUT_CTL;
        }
        if(m_order_L < - SPEED_MAX_WITHOUT_CTL){
            m_order_L = - SPEED_MAX_WITHOUT_CTL;
        }
        else if(m_order_L > SPEED_MAX_WITHOUT_CTL){
            m_order_L = SPEED_MAX_WITHOUT_CTL;
        }
    }
}
