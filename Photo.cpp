/// \file Photo.cpp

#include <iostream>
#include "Photo.h"
#include "AbstractMedia.h"

Photo::Photo(std::string name, std::string fileName, float latitude, 
                float longitude) : AbstractMedia(name, fileName) {
    _latitude = latitude;
    _longitude = longitude;
}

void Photo::print(std::ostream & output) const { 
    output << std::endl << "The name of the Photo is : " << 
    this->getName() << std::endl << 
    "The file path is : " << this->getFileName() << std::endl << 
    "The latitude of the photo is : " << this->getLatitude() << std::endl <<
    "The longitude of the photo is : " << this->getLongitude() << std::endl;
}
