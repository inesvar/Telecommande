/// \file AbstractMedia.cpp

#include <iostream>
#include "AbstractMedia.h"

void AbstractMedia::print(std::ostream & output) const { 
    output << "The name of the base class is : " << 
                this->getName() << std::endl << "and the file path is : " << 
                this->getFileName() << std::endl << std::endl;
}
