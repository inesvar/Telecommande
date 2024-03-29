#include <iostream>
#include "AbstractMedia.h"


#ifndef PHOTO
#define PHOTO

/**
 * @brief Photo, has a latitude and longitude (float values)
 * 
*/
class Photo : public AbstractMedia {

    private:
        /**
         * @brief Latitude of the place where the photo was taken
         * 
        */
        float _latitude{};

        /**
         * @brief Longitude of the place where the photo was taken
         * 
        */
        float _longitude{};


    public:
        /**
         * @brief Construct a new Photo object
         * 
        */
        Photo() {}

        /**
         * @brief Construct a new Photo object
         * 
         * \param name name of the file
         * \param filename path to the photo file
         * 
        */
        Photo(const std::string & name, const std::string & filename) : AbstractMedia(name, filename) {};

        /**
         * @brief Construct a new Photo object
         * 
         *  \param name name of the photo
         *  \param filename path to the photo file
         *  \param latitude latitude of the place where the photo was taken
         *  \param longitude longitude of the place where the photo was taken
        */
        Photo(const std::string & name, const std::string & filename, float latitude, float longitude);

        /**
         * @brief Destroy the Photo object
         * 
        */
        ~Photo() {std::cout << "Photo " 
                    << getName() << " destructor" << std::endl;}

        /**
         * @brief Gets the latitude of the photo
         * 
         * @return float 
        */
        float getLatitude() const {return _latitude;}

        /**
         * @brief Gets the longitude of the photo
         * 
         * @return float 
        */
        float getLongitude() const {return _longitude;}

        /**
         * @brief Sets the latitude of the photo
         * 
         * @param latitude 
        */
        void setLatitude(float latitude) {_latitude = latitude;}

        /**
         * @brief Sets the longitude of the photo
         * 
         * @param longitude 
        */
        void setLongitude(float longitude) {_longitude = longitude;}

        /**
         * @brief Prints the instance variables of the photo
         * 
         * @param output std::cout or a file
        */
        void print(std::ostream & output) const override;

        /**
         * @brief Displays the photo
         * 
        */
        void play() const override {system(("imagej " + getfilename() + " &").data()); }

        /**
         * @brief Returns the name of the class
         * 
         * @return const std::string& 
         */
        void classname(std::ostream & file) const override;

        /**
         * @brief Save a multimedia object to a file
         * 
         * @param file 
         */
        void save(std::ostream & file) const override;

        /**
         * @brief Restore a multimedia object from a file
         * 
         * @param file 
         */
        void restore(std::istream & file) override;
};

#endif

