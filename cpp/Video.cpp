/// \file Video.cpp

#include <iostream>
#include "Video.h"

Video::Video(const std::string & name, const std::string & filename, unsigned int length) : 
                AbstractMedia(name, filename) {
    this->_length = length;
}

void Video::print(std::ostream & output) const { 
    output << "name : " << 
    this->getName()<<
    " ; path : " << this->getfilename()<<
    " ; length : " << this->getLength()<< "          ";
}

void Video::classname(std::ostream & file) const {
    file << "Video" << std::endl;
}

void Video::save(std::ostream & file) const { 
    AbstractMedia::save(file);
    file << " " << this->getLength();
}

void Video::restore(std::istream & file) {
    AbstractMedia::restore(file);
    file >> _length;
}
