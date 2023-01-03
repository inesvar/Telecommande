#define PART8

#ifdef PART8

#include <iostream>
#include "AbstractMedia.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "MediaGroup.h"

int main(int argc, const char* argv[]) {

    MediaGroup * mg = new MediaGroup("vacances");

    mg->push_back(new Video("VIDEO", "./video.webm", 10));
    mg->push_back(new Photo("PHOTO", "./Gala.jpg", 1, 2.4));
    
    unsigned int numberOfChapters = 5;
    unsigned int chapters[] = {2,5,2,2,4,2};
    mg->push_back(new Film("FILM", "./video.webm", 15, numberOfChapters, chapters));

    std::cout << "The name of the group is : " << mg->getName() << std::endl;

    for (auto & it : *mg) {
        it->print(std::cout);
    }

    return 0;
}


#endif
