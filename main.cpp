#define PART1_7
#define PART8_9



#include <iostream>
#include <memory>
#include "AbstractMedia.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "MediaGroup.h"

int main(int argc, const char* argv[]) {

    #ifdef PART8_9

    std::cout << std::endl << "Parts 8 to 9" << std::endl << std::endl;

    std::shared_ptr<Video> sharedVideoPtr = std::make_shared<Video>("SHARED_VIDEO", "./kabuki.gif", 10);
    std::shared_ptr<Photo> sharedPhotoPtr = std::make_shared<Photo>("SHARED_PHOTO", "./kabuki.jpg", 1, 2.4);

    MediaGroup * mgKabuki = new MediaGroup("Kabuki");

    mgKabuki->push_back(sharedVideoPtr);
    mgKabuki->push_back(sharedPhotoPtr);
    mgKabuki->push_back(std::make_shared<Photo>("PRIVATE_PHOTO", "./kabuki.jpg", 3, 2.4));

    std::cout << "GROUP : " << mgKabuki->getName() << std::endl;

    for (auto & it : *mgKabuki) {
        it->print(std::cout);
    }

    MediaGroup * mgJapan = new MediaGroup("Japan");

    mgJapan->push_back(sharedPhotoPtr);
    //mgJapan->push_back(sharedVideoPtr);
    mgJapan->push_back(std::make_shared<Photo>("PRIVATE_PHOTO_2", 
                        "./sakura.jpg", 1, 2.4));
    mgJapan->push_back(std::make_shared<Photo>("PRIVATE_PHOTO_3", 
                        "./kanji.png", 1, 2.4));

    std::cout << "GROUP : " << mgJapan->getName() << std::endl;

    for (auto & it : *mgJapan) {
        it->print(std::cout);
    }

    std::cout << "ERASING GROUP Kabuki... Only the private objects will be destroyed" 
                        << std::endl;
    mgKabuki->clear();

    std::cout << "ERASING GROUP Japan... The private objects and shared objects will" 
                        << "be destroyed" << std::endl;
    mgJapan->clear();

    #endif

///////// ///////// ///////// ///////// ///////// ///////// ///////// ///////// 

    #ifdef PART1_7
    std::cout << std::endl << "Parts 1 to 7" << std::endl << std::endl;

    int numberOfObjects = 3;
    AbstractMedia ** objects = new AbstractMedia * [numberOfObjects];

    objects[0] = new Video("VIDEO", "./kabuki.gif", 10);
    objects[1] = new Photo("PHOTO", "./kabuki.jpg", 1, 2.4);

    for (int i = 0 ; i < numberOfObjects-1 ; i++) {
        //objects[i]->play();
        objects[i]->print(std::cout);
    }
    
    unsigned int numberOfChapters = 5;
    unsigned int chapters[] = {2,5,2,2,4,2};
    Film * film = new Film("FILM", "./kabuki.gif", 15, numberOfChapters, chapters);
    objects[2] = new Film("OTHER_FILM", "./kabuki.gif", 15, numberOfChapters, chapters);
    film->print(std::cout);

    numberOfChapters = 4;
    unsigned int chapters2[] = {5,2,6,2};
    film->setChapters(numberOfChapters, chapters2);
    std::cout << std::endl << "Changing the chapters of FILM..." << std::endl;

    film->print(std::cout);

    unsigned int * chapters3 = film->getChapters();
    unsigned int nb_chapters = film->getNumberOfChapters();
    chapters3[0]=50;
    std::cout << std::endl << "Getting the FILM's chapters and setting " <<
                "the duration of the first chapter to 50..." << std::endl;

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

    #endif

///////// ///////// ///////// ///////// ///////// ///////// ///////// ///////// 

    return 0;
}