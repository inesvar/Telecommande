#include <string.h>
#include "Film.h"

Film::Film(const std::string & name, const std::string & fileName, unsigned int length, 
            unsigned int numberOfChapters, unsigned int * chapters) : 
            Video(name, fileName, length) {
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
    output << "The name of the film is : " << getName() << 
    std::endl << "The file path is : " << getFileName() << std::endl << 
    "The length of the video is : " << getLength() << std::endl <<
    "There are " << getNumberOfChapters() << " chapters" << std::endl;
    for (unsigned int i = 0; i < _numberOfChapters; i++) {
        output << "Chapter number " << i+1 << " : " << _chapters[i] << std::endl;
    }
    output << std::endl;
}