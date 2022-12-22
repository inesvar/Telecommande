/// \file main.cpp

#include <iostream>
#include "AbstractMedia.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"

int main(int argc, const char* argv[]) {

    int numberOfObjects = 3;
    AbstractMedia ** objects = new AbstractMedia * [numberOfObjects];

    objects[0] = new Video("VIDEO", "./video.webm", 10);
    objects[1] = new Photo("PHOTO", "./Gala.jpg", 1, 2.4);

    for (int i = 0 ; i < numberOfObjects-1 ; i++) {
        //objects[i]->play();
        objects[i]->print(std::cout);
    }
    
    unsigned int numberOfChapters = 5;
    unsigned int chapters[] = {2,5,2,2,4,2};
    Film * film = new Film("FILM", "./video.webm", 15, numberOfChapters, chapters);
    objects[2] = new Film("OTHER_FILM", "./video.webm", 15, numberOfChapters, chapters);
    film->print(std::cout);

    numberOfChapters = 4;
    unsigned int chapters2[] = {5,2,6,2};
    film->setChapters(numberOfChapters, chapters2);
    std::cout << std::endl << "Changing the chapters of FILM..." << std::endl;

    film->print(std::cout);

    unsigned int * chapters3 = film->getChapters();
    unsigned int nb_chapters = film->getNumberOfChapters();
    chapters3[0]=50;
    std::cout << std::endl << "Getting the FILM's chapters and setting th duration of the first chapter to 50..." << std::endl;

    film->print(std::cout);

    Film newFilm(*film);
    std::cout << std::endl << "Copying FILM into NEW_FILM and modifying " <<
                "the chapters of NEW_FILM..." << std::endl;
    newFilm.setName("NEW_FILM");
    newFilm.setChapters(nb_chapters, chapters3);

    newFilm.print(std::cout);
    film->print(std::cout);


    std::cout << std::endl << "Deleting all the objects..." << std::endl;
    /* Correct deletion :*/
    for (int i = 0; i < numberOfObjects; i++) {
        delete objects[i];
    }
    delete [] objects;
    delete film;

    return 0;
}


#endif
