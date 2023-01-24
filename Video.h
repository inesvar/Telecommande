#ifndef VIDEO
#define VIDEO

#include <iostream>
#include "AbstractMedia.h"


/**
 * @brief Video, has a length (integral value)
 * 
*/
class Video : public AbstractMedia {

    private:
        /**
         * @brief Length of the video
         * 
        */
        unsigned int _length{};

    public:
        /**
         * @brief Construct a new Video object
         * 
        */
        Video() {}

        /**
         * @brief Construct a new Video object
         * 
         * \param name name of the video
         * \param filename path to the video file
         * 
        */
        Video(const std::string & name, const std::string & filename) : AbstractMedia(name, filename) {};

        /**
         * @brief Construct a new Video object
         * 
         *  \param name name of the video
         *  \param filename path to the video file
         *  \param length length of the video
        */
        Video(const std::string & name, const std::string & filename, unsigned int length);

        /**
         * @brief Destroy the Video object
         * 
        */
        ~Video() {std::cout << "Video " 
                    << getName() << " destructor" << std::endl;}

        /**
         * @brief Get the length of the video
         * 
         * @return unsigned int 
        */
        unsigned int getLength() const {return _length;}

        /**
         * @brief Set the length of the video
         * 
         * @param length 
        */
        void setLength(unsigned int length) {_length = length;}

        /**
         * @brief Prints the instance variables
         * 
         * @param output std::cout or file
        */
        void print(std::ostream & output) const override;

        /**
         * @brief Plays the video
         * 
        */
        void play() const override {system(("mpv " + getfilename() + " &").data()); }
};

#endif

