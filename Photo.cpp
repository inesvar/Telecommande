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
    output << "name : " << getName()<< 
    " ; path : " << getfilename()<< " ; latitude : " << getLatitude()<<
    " ; longitude : " << getLongitude()<< "                                                                                               ";
}

void Photo::classname(std::ostream & file) const {
    file << "Photo" << std::endl;
}

void Photo::save(std::ostream & file) const { 
    AbstractMedia::save(file);
    file << " " << this->getLatitude() << " " << this->getLongitude();
}

void Photo::restore(std::istream & file) {
    AbstractMedia::restore(file);
    file >> _latitude >> _longitude;
}

