#include <string.h>
#include "Film.h"

Film::Film(const std::string & name, const std::string & filename, unsigned int length, 
            unsigned int numberOfChapters, unsigned int * chapters) : 
            Video(name, filename, length) {
    _numberOfChapters = numberOfChapters;
    _chapters = new unsigned int[numberOfChapters];
    for (unsigned int i = 0; i < numberOfChapters; i++) {
        _chapters[i] = chapters[i];
    }
}

Film::Film(const Film& original) : Video(original) {
    _numberOfChapters = original._numberOfChapters;
    _chapters = new unsigned int[_numberOfChapters];
    for (unsigned int i = 0; i < _numberOfChapters; i++) {
        _chapters[i] = original._chapters[i];
    }
}

Film::~Film() {
    std::cout << "Film " 
                    << getName() << " destructor" << std::endl;
    delete _chapters;
}


void Film::setChapters(unsigned int numberOfChapters, unsigned int * chapters) {
    _numberOfChapters = numberOfChapters;
    delete _chapters;
    _chapters = new unsigned int[numberOfChapters];
    for (unsigned int i = 0; i < numberOfChapters; i++) {
        _chapters[i] = chapters[i];
    }
}

unsigned int * Film::getChapters() const {
    unsigned int * allChapters = new unsigned int[_numberOfChapters];
    for (unsigned int i = 0; i < _numberOfChapters; i++) {
        allChapters[i] = _chapters[i];
    }
    return allChapters;
}

unsigned int Film::getNumberOfChapters() const {
    return _numberOfChapters;
}

void Film::print(std::ostream & output) const { 
    /*output << "The name of the film is : " << getName() << 
    std::endl << "The file path is : " << getfilename()<< "     " << 
    "The length of the video is : " << getLength()<< "     " <<
    "There are " << getNumberOfChapters() << " chapters"<< "     ";
    for (unsigned int i = 0; i < _numberOfChapters; i++) {
        output << "Chapter number " << i+1 << " : " << _chapters[i]<< "     ";
    }
    output<< "     ";*/
    output << "name : " << getName() << " ; path : " << getfilename() << 
    " ; length : " << getLength()<< 
    " ; (" << getNumberOfChapters() << ") chapters : ";
    for (unsigned int i = 0; i < _numberOfChapters - 1; i++) {
        output << _chapters[i]<< ", ";
    }
    output<< _chapters[_numberOfChapters-1] << "                                                                                               ";
}

void Film::classname(std::ostream & file) const {
    file << "Film" << std::endl;
}

void Film::save(std::ostream & file) const {
    Video::save(file);
    file << " "<< _numberOfChapters << " ";
    for (unsigned int i = 0; i < _numberOfChapters - 1; i++) {
        file << _chapters[i] << " ";
    }
    file << _chapters[_numberOfChapters - 1];
}

void Film::restore(std::istream & file) {
    Video::restore(file);
    file >> _numberOfChapters;
    delete _chapters;
    _chapters = new unsigned int[_numberOfChapters];
    for (unsigned int i = 0; i < _numberOfChapters; i++) {
        file >> _chapters[i];
    }
}