//
// Created by da0ma on 9/29/2026.
//
#ifndef PIGDIE2_DIE_H
#define PIGDIE2_DIE_H
#include <random>

class Die {
private: //learning, not needed in a class
    int m_value;
    int m_numOfSides;
public:
    Die();
    void set_numOfSides(int numOfSides);
    int getNumOfSides();
    void setDieValue();
    int getDieValue();
};


#endif //PIGDIE2_DIE_H
