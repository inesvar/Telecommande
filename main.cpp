#define PART8

#ifdef PART8

#include <iostream>
#include <memory>
#include "AbstractMedia.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "MediaGroup.h"

int main(int argc, const char* argv[]) {

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
    mgJapan->push_back(std::make_shared<Photo>("PRIVATE_PHOTO_2", "./sakura.jpg", 1, 2.4));
    mgJapan->push_back(std::make_shared<Photo>("PRIVATE_PHOTO_3", "./kanji.png", 1, 2.4));
    
    unsigned int numberOfChapters = 5;
    unsigned int chapters[] = {2,5,2,2,4,2};
    mgJapan->push_back(std::make_shared<Film>("PRIVATE_FILM", "./kabuki.gif", 15, numberOfChapters, chapters));

    std::cout << "GROUP : " << mgJapan->getName() << std::endl;

    for (auto & it : *mgJapan) {
        it->print(std::cout);
    }

    std::cout << "ERASING GROUP Kabuki... Only the private objects will be destroyed" << std::endl;
    mgKabuki->clear();

    std::cout << "ERASING GROUP Japan... The private objects and shared objects will be destroyed" << std::endl;
    mgJapan->clear();

    return 0;
}


#endif
