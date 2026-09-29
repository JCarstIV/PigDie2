//
// Created by da0ma on 9/29/2026.
//

#include "DIE.h"

Die::Die() {
    m_numOfSides = 6;
    setDieValue();
}

//conditional changing of variable
void Die::set_numOfSides(int numOfSides) {
    switch (numOfSides) {
        case 4:
            m_numOfSides = 4;
            break;
        case 6:
            m_numOfSides = 6;
            break;
        case 8:
            m_numOfSides = 8;
            break;
        default:
            m_numOfSides = 6;
    }

}
int Die::getNumOfSides() {
    return m_numOfSides;
}

//Set private thing
void Die::setDieValue() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, m_numOfSides);
    m_value = dis(gen);
}

//Get private thing
int Die::getDieValue() {
    return m_value;
    //put rules for accessing data here, not in setting
}