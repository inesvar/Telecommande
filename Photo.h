/// \file Photo.h
#include "AbstractMedia.h"
#include <iostream>

/// \class Photo
/// \brief This superclass represents a photo
///
/// \param _latitude latitude of the place where the photo was taken
/// \param _longitude longitude of the place where the photo was taken
class Photo : public AbstractMedia {

    private:
        /// \brief latitude of the place where the photo was taken
        float _latitude{};

        /// \brief longitude of the place where the photo was taken
        float _longitude{};


    public:
        /// \brief Constructor
        Photo() {}

        /// \brief Constructor
        /// \param name name of the photo
        /// \param fileName path to the photo file
        /// \param latitude latitude of the place where the photo was taken
        /// \param longitude longitude of the place where the photo was taken
        Photo(std::string name, std::string fileName, float latitude, float longitude);

        /// \brief Destructor
        ~Photo() {std::cout << "Photo destructor" << std::endl;}

        /// \brief Getter
        /// \return _latitude : latitude of the photo
        unsigned int getLatitude() const {return _latitude;}

        /// \brief Getter
        /// \return _longitude : longitude of the photo
        unsigned int getLongitude() const {return _longitude;}


        /// \brief Prints the instance variables of the photo
        /// \param output the output file, or cout
        void print(std::ostream & output) const override;

        /// @brief Displays the photo
        void play() const override {system(("imagej " + getFileName() + " &").data()); }
};

