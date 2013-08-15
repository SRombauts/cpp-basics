/**
 * @file  Object.h
 * @brief Object Description of an object
 */

#include <string>

/**
 * @brief Description of an object
 */
class Object
{
// Public methods
public:
    Object (const char* aName, int aValue);
    virtual ~Object ();

    // simple getters
    inline const std::string&   getName()   const;
    inline int                  getValue()  const;

// Private variable membres
private:
    std::string mName;  // Name of the objet
    int         mValue; // Value of the objet
};


/**
 * @brief Const method returning the name of the object by const-reference for efficiency
 */
inline const std::string& Object::getName() const
{
    return mName;
}
/**
 * @brief Const method returning the value of the object by copy as it is a simple type
 */
inline int Object::getValue() const
{
    return mValue;
}

