#define PART8

#ifdef PART8

#include <iostream>
#include "AbstractMedia.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "MediaGroup.h"

int main(int argc, const char* argv[]) {

    MediaGroup * mg = new MediaGroup("Kabuki");

    mg->push_back(new Video("VIDEO", "./kabuki.gif", 10));
    mg->push_back(new Photo("PHOTO", "./kabuki.jpg", 1, 2.4));

    std::cout << "GROUP : " << mg->getName() << std::endl;

    for (auto & it : *mg) {
        it->print(std::cout);
        it->play();
    }



    MediaGroup * mgJapon = new MediaGroup("Japon");

    mgJapon->push_back(new Photo("PHOTO", "./kabuki.jpg", 1, 2.4));
    mgJapon->push_back(new Photo("PHOTO", "./sakura.jpg", 1, 2.4));
    mgJapon->push_back(new Photo("PHOTO", "./kanji.png", 1, 2.4));
    
    unsigned int numberOfChapters = 5;
    unsigned int chapters[] = {2,5,2,2,4,2};
    mgJapon->push_back(new Film("FILM", "./kabuki.gif", 15, numberOfChapters, chapters));

    std::cout << "GROUP : " << mgJapon->getName() << std::endl;

    for (auto & it : *mgJapon) {
        it->print(std::cout);
    }

    return 0;
}


#endif
