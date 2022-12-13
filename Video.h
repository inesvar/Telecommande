/// \file Video.h
#include "BaseClass.h"
#include <iostream>

/// \class Video
/// \brief This superclass represents a video
///
/// \param _length length of the video
class Video : public BaseClass {

    private:
        /// \brief the length of the video
        float _length{};

    public:
        /// \brief Constructor 
        Video() {}

        /// \brief Constructor
        /// \param name name of the video
        /// \param fileName path to the video file
        /// \param length length of the video
        Video(std::string name, std::string fileName, float length);

        /// \brief Destructor
        ~Video() {std::cout << "Video destructor" << std::endl;}

        /// \brief Getter
        /// \return _length : the length of the video
        unsigned int getLength() const {return _length;}

        /// \brief Prints the instance variables of the video
        /// \param output the output file, or cout
        void print(std::ostream & output) const override;

        /// \brief Plays the video
        void play() const override {system(("mpv " + getFileName() + " &").data()); }
};

