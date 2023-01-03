#include <iostream>
#include "AbstractMedia.h"

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
         *  \param name name of the photo
         *  \param fileName path to the photo file
         *  \param latitude latitude of the place where the photo was taken
         *  \param longitude longitude of the place where the photo was taken
        */
        Photo(std::string name, std::string fileName, float latitude, float longitude);

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
        void play() const override {system(("imagej " + getFileName() + " &").data()); }
};

