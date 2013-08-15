/**
 * @file  Object.cpp
 * @brief Object Description of an object
 */

#include "Object.h"

#include <iostream> // std::cout

/**
 * @brief Constructeur : initialize variables
 *
 * @param[in] aName     Name of the object
 * @param[in] aValue    Value of the object
*/
Object::Object(const char* aName, int aValue) :
    // Initialization list : beware, they are initialized in the order of their declaration in Object.h, not the order here!
    mName(aName),
    mValue(aValue)
{
    std::cout << "Object: constructor" << std::endl;
}

/**
 * @brief Destructeur : release the string
*/
Object::~Object()
{
    std::cout << "Object: destructor" << std::endl;
}
