/**
 * @file  main.cpp
 * @brief Entry point
 */

#include "Object.h"

#include <cstdlib>  // EXIT_SUCCESS
#include <iostream> // std::cout
#include <memory>   // std::shared_ptr

/**
 * @brief Demonstrate the lifespan of an object constructed on the stack, as a local variable
 *        destructor is called at the end of the variable scope
 *
 * output:
+createObjectOnStack
Object: constructor
Object: test=123
Object: destructor
-createObjectOnStack
*/
void createObjectOnStack()
{
    std::cout << "+createObjectOnStack\n";

    // Scope used only for testing purpose
    {
        Object obj("test", 123); // Constructor is called here

        std::cout << "Object: " << obj.getName() << "=" << obj.getValue() << std::endl; // here std::endl is more elegant than "\n"
    
    } // Destructor is called here

    std::cout << "-createObjectOnStack\n";
}

/**
 * @brief Demonstrate the lifespan of an object constructed on the heap, with "new"
 *        destructor is called only when (and if!) "delete" is called
 *
 * output:
+createObjectOnHeap
Object: constructor
Object: test=123
Object: test=123
Object: destructor
-createObjectOnHeap
 */
void createObjectOnHeap()
{
    Object* pObj = NULL; // No constructor called here...

    std::cout << "+createObjectOnHeap\n";

    // Scope used only for testing purpose
    {
        Object* pObjLocal = new Object("test", 123); // Constructor is called here

        std::cout << "Object: " << pObjLocal->getName() << "=" << pObjLocal->getValue() << std::endl; // here std::endl is more elegant than "\n"

        pObj = pObjLocal; // saving pointer to delete it latter on

    } // No destructor called here...

    std::cout << "Object: " << pObj->getName() << "=" << pObj->getValue() << std::endl; // here std::endl is more elegant than "\n"

    delete pObj; // Destructor is explicitly called here
    pObj = NULL;

    std::cout << "-createObjectOnHeap\n";
}


typedef std::shared_ptr<Object> ObjectPtr; // Shared pointer to an Object

/**
 * @brief Demonstrate the lifespan of an object constructed with a shared_ptr (on the heap)
 *        destructor is called when no more pointer share the object
 *
 * output:
+createObjectOnHeapWithSharedPtr1
Object: constructor
Object: test=123
Object: destructor
-createObjectOnHeapWithSharedPtr1
 */
void createObjectOnHeapWithSharedPtr1()
{
    ObjectPtr ObjPtr; // No constructor called here...

    std::cout << "+createObjectOnHeapWithSharedPtr1\n";

    // Scope used only for testing purpose
    {
        ObjectPtr ObjLocalPtr = ObjectPtr(new Object("test", 123)); // Constructor is called here

        std::cout << "Object: " << ObjLocalPtr->getName() << "=" << ObjLocalPtr->getValue() << std::endl; // here std::endl is more elegant than "\n"

    } //  Destructor is called here

    std::cout << "-createObjectOnHeapWithSharedPtr1\n";
}

/**
 * @brief Demonstrate the lifespan of an object constructed with a shared_ptr (on the heap)
 *        destructor is called when no more pointer share the object
 *
 * output:
+createObjectOnHeapWithSharedPtr2
Object: constructor
Object: test=123
Object: test=123
Object: destructor
-createObjectOnHeapWithSharedPtr2
 */
void createObjectOnHeapWithSharedPtr2()
{
    ObjectPtr ObjPtr; // No constructor called here...

    std::cout << "+createObjectOnHeapWithSharedPtr2\n";

    // Scope used only for testing purpose
    {
        ObjectPtr ObjLocalPtr = ObjectPtr(new Object("test", 123)); // Constructor is called here

        std::cout << "Object: " << ObjLocalPtr->getName() << "=" << ObjLocalPtr->getValue() << std::endl; // here std::endl is more elegant than "\n"

        ObjPtr = ObjLocalPtr; // share the ownership of he Object

    } // No destructor called here (as ObjPtr still point to Object) ...

    std::cout << "Object: " << ObjPtr->getName() << "=" << ObjPtr->getValue() << std::endl; // here std::endl is more elegant than "\n"

    ObjPtr.reset(); // Destructor is implicitly called here (as no more pointer share the Object ownership)

    std::cout << "-createObjectOnHeapWithSharedPtr2\n";
}

/**
 * @brief Entry point
 * 
 * @arg[in] argc    Parameters Count
 * @arg[in] argv    Parameters Values
 */
int main(int argc, char* argv[])
{
    std::cout << "Hello World !\n"; // no need for std::endl

    createObjectOnStack();
    createObjectOnHeap();
    createObjectOnHeapWithSharedPtr1();
    createObjectOnHeapWithSharedPtr2();

    std::cout << "Bye !\n";

    return EXIT_SUCCESS;
}
