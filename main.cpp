#define PART1_7
#define PART8_9
#define PART10_13


#include <bits/stdc++.h>
#include <iostream>
#include <memory>
#include "AbstractMedia.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "MediaGroup.h"
#include "MediaIndex.h"
#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "tcpserver.h"

typedef std::shared_ptr<AbstractMedia> AbstractMediaPtr;
typedef std::shared_ptr<MediaGroup> MediaGroupPtr;
typedef std::shared_ptr<Photo> PhotoPtr;
typedef std::shared_ptr<Video> VideoPtr;
typedef std::shared_ptr<Film> FilmPtr;

int PORT = 3331;

int main(int argc, const char* argv[]) {

///////// ///////// ///////// ///////// ///////// ///////// ///////// /////////

    #ifdef PART10_13

    std::cout<< std::endl << "Parts 10 to 11"<< std::endl<< std::endl;

    // creates a MediaIndex mi with two groups and some files
    MediaIndex * mi = new MediaIndex();

    mi->read("save");

    // creates the TCPServer
    auto* server = new TCPServer( [&](std::string const& request, std::string& response) {

    // the request sent by the client to the server
    std::cout << "request: " << request<< std::endl;

    // check if there's at least two words in the request
    int numberOfWords = std::count(request.begin(), request.end(), ' ');

    std::string action, name, filename;

    // store the first word of the request in action and the second word of the request in file
    std::istringstream iss(request);
    iss >> action >> name;

    if (numberOfWords >= 3) {
        iss >> filename;
    }

    try {
        if (action == "find") {
            AbstractMediaPtr media = mi->findMediaObject(name);
            if (media != nullptr) {
                response = name + " was found";
            }

        } else if (action == "find_g") {
            MediaGroupPtr group = mi->findMediaGroup(name);
            if (group != nullptr) {
                response = name + " was found";
            }

        } else if (action == "play") {
            AbstractMediaPtr media = mi->findMediaObject(name);
            if (media != nullptr) {
                response = name + " was found";
                media->play();
            }

        } else if (action == "print") {
            AbstractMediaPtr media = mi->findMediaObject(name);
            std::stringstream ss;
            if (media != nullptr) {
                media->print(ss);
                response = ss.str();
            }

        } else if (action == "print_g") {
            MediaGroupPtr group = mi->findMediaGroup(name);
            std::stringstream ss;
            if (group != nullptr) {
                group->print(ss);
                response = ss.str();
            }

        } else if (action == "create_photo") {
            mi->template createNewObject<Photo>(name, filename);
            response = "The photo "+name+" was created";

        } else if (action == "create_film") {
            mi->template createNewObject<Film>(name, filename);
            response = "The film "+name+" was created";

        } else if (action == "create_video") {
            mi->template createNewObject<Video>(name, filename);
            response = "The video "+name+" was created";

        } else if (action == "create_g") {
            mi->createGroup(name);
            response = "The group "+name+" was created";
        
        } else if (action == "erase") {
            mi->eraseMediaObject(name);
            response = "The media "+name+" was erased";

        } else if (action == "erase_g") {
            mi->eraseMediaGroup(name);
            response = "The group "+name+" was erased";
        
        } else if (action == "save") {
            mi->save(name);
            response = "The entire MediaIndex was saved to file "+name;
        
        } else if (action == "restore") {
            mi->read(name);
            response = "MediaIndex was saved to file "+name;

        } else if (action == "print_all") {
            std::stringstream ss;
            mi->print(ss);
            response = ss.str();

        } else if (action == "erase_all") {
            mi->erase();
            response = "The entire MediaIndex was erased";

        } else {
            response = "invalid request, there should be at least two words separated by "
                            "one space. The possible requests are : find <name>, "
                            "find_g <group_name>, play <name>, "
                            "print <name>, print_g <group_name>, create_photo <name> <path>,"
                            " create_film <name> <path>, create_video <name> <path>, create_g <name>, "
                            "erase <name>, erase_g <name>, save <filename>, read <filename>, print_all, erase_all";
        }
    } catch (std::exception &e) {
        response = e.what();
    }


    // return false would close the connection with the client
    return true;
  });


    // launch the server on an infinite loop
    std::cout << "Starting Server on port " << PORT<< std::endl;

    int status = server->run(PORT);

    // if the server could not be started, print an error message and exit
    if (status < 0) {
        std::cerr << "Could not start Server on port " << PORT<< std::endl;
        return 1;
    }


    #endif

///////// ///////// ///////// ///////// ///////// ///////// ///////// /////////

    #ifdef PART8_9

    std::cout<< std::endl << "Parts 8 to 9"<< std::endl<< std::endl;

    std::cout<< std::endl << "Creating two groups 'Kabuki' and 'Japan'"<< std::endl<< std::endl;

    std::shared_ptr<Video> sharedVideoPtr = std::make_shared<Video>("SHARED_VIDEO", "./kabuki.gif", 10);
    std::shared_ptr<Photo> sharedPhotoPtr = std::make_shared<Photo>("SHARED_PHOTO", "./kabuki.jpg", 1, 2.4);

    MediaGroup * mgKabuki = new MediaGroup("Kabuki");

    mgKabuki->push_back(sharedVideoPtr);
    mgKabuki->push_back(sharedPhotoPtr);
    mgKabuki->push_back(std::make_shared<Photo>("UNIQUE_PHOTO", "./kabuki.jpg", 3, 2.4));

    mgKabuki->print(std::cout);

    MediaGroup * mgJapan = new MediaGroup("Japan");

    mgJapan->push_back(sharedPhotoPtr);
    mgJapan->push_back(sharedVideoPtr);
    mgJapan->push_back(std::make_shared<Photo>("UNIQUE_PHOTO_2", 
                        "./sakura.jpg", 1, 2.4));
    mgJapan->push_back(std::make_shared<Photo>("UNIQUE_PHOTO_3", 
                        "./kanji.png", 1, 2.4));

    mgJapan->print(std::cout);

    std::cout << std::endl << std::endl << "ERASING main's pointers to shared objects..." << std::endl;
    sharedPhotoPtr.reset();
    sharedVideoPtr.reset();

    std::cout << "ERASING GROUP Kabuki... Only the unique objects will be destroyed" 
                       << std::endl;
    mgKabuki->clear();

    std::cout << "ERASING GROUP Japan...  All remaining objects will be destroyed"<< std::endl;
    mgJapan->clear();

    #endif

///////// ///////// ///////// ///////// ///////// ///////// ///////// ///////// 

    #ifdef PART1_7
    std::cout<< std::endl << "Parts 1 to 7"<< std::endl<< std::endl;

    std::cout<< std::endl << "Creating a few objects and making sure the film's chapters work correctly"<< std::endl << std::endl;

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
    std::cout<< std::endl << std::endl << "Changing the chapters of FILM..."<< std::endl;

    film->print(std::cout);

    unsigned int * chapters3 = film->getChapters();
    unsigned int nb_chapters = film->getNumberOfChapters();
    chapters3[0]=50;
    std::cout<< std::endl << std::endl << "Getting the FILM's chapters and setting " <<
                "the duration of the first chapter to 50..."<< std::endl;

    film->print(std::cout);

    Film newFilm(*film);
    std::cout<< std::endl << std::endl << "Copying FILM into NEW_FILM and modifying " <<
                "the chapters of NEW_FILM..."<< std::endl;
    newFilm.setName("NEW_FILM");
    newFilm.setChapters(nb_chapters, chapters3);

    newFilm.print(std::cout);
    film->print(std::cout);


    std::cout<< std::endl << std::endl << "Deleting all the objects..."<< std::endl;
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