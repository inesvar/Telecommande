/// \file Video.cpp

#include <iostream>
#include "Video.h"

Video::Video(std::string name, std::string fileName, float length) : BaseClass(name, fileName) {
    _length = length;
}

void Video::print(std::ostream & output) const { 
    output << "The name of the video is : " << this->getName() << std::endl << 
    "The file path is : " << this->getFileName() << std::endl << 
    "The length of the video is : " << this->getLength() << std::endl;
}
