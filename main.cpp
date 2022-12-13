/// \file main.cpp

#include <iostream>
#include "BaseClass.h"
#include "Video.h"
#include "Photo.h"

int main(int argc, const char* argv[])
{
    Video * v = new Video("us", "./video.webm", 0.2);

    v->play();

    auto p = new Photo("us", "./Gala.jpg", 0, 0);

    p->play();

    return 0;
}
