/// \file BaseClass.cpp

#include <iostream>
#include "BaseClass.h"

void BaseClass::print(std::ostream & output) const { 
    output << "The name of the base class is : " << this->getName() << std::endl << "and the file path is : " << this->getFileName() << std::endl;
}
