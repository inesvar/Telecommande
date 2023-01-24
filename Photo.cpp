/// \file Photo.cpp

#include <iostream>
#include "Photo.h"
#include "AbstractMedia.h"

Photo::Photo(const std::string & name, const std::string & filename, float latitude, 
                float longitude) : AbstractMedia(name, filename) {
    _latitude = latitude;
    _longitude = longitude;
}

void Photo::print(std::ostream & output) const { 
    output << "The name of the Photo is : " << 
    this->getName()<< "     " << 
    "The file path is : " << this->getfilename()<< "     " << 
    "The latitude of the photo is : " << this->getLatitude()<< "     " <<
    "The longitude of the photo is : " << this->getLongitude()<< "     "<< "     ";
}
