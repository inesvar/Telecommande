/// \file main.cpp

#include <iostream>
#include "AbstractMedia.h"
#include "Video.h"
#include "Photo.h"

int main(int argc, const char* argv[]) {

    int numberOfObjects = 2;

    AbstractMedia * objects[numberOfObjects];

    objects[0] = new Video("us", "./video.webm", 0.2);
    objects[1] = new Photo("us", "./Gala.jpg", 1, 2);

    for (int i = 0 ; i < numberOfObjects ; i++) {
        objects[i]->play();
        objects[i]->print(std::cout);
    }

    return 0;
}
