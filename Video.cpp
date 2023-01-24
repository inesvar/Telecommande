/// \file Video.cpp

#include <iostream>
#include "Video.h"

Video::Video(const std::string & name, const std::string & filename, unsigned int length) : 
                AbstractMedia(name, filename) {
    this->_length = length;
}

void Video::print(std::ostream & output) const { 
    output << "The name of the video is : " << 
    this->getName()<< "     " << 
    "The file path is : " << this->getfilename()<< "     " << 
    "The length of the video is : " << this->getLength()<< "     "<< "     ";
}
