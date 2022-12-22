/// \file Film.h
#include "AbstractMedia.h"
#include "Video.h"
#include <iostream>

/// \class Film
/// \brief This superclass represents a movie
///
/// \param _numberOfChapters number of chapters in the movie
/// \param _chapters duration of each chapter of the movie
class Film : public Video {

    private:
        /// \brief duration of each chapter of the movie
        unsigned int * _chapters{};

        /// @brief number of chapters in the movie
        unsigned int _numberOfChapters{};

    public:
        /// \brief Constructor 
        Film() {}

        /// @brief Constructor
        /// \param name name of the movie
        /// \param fileName path to the movie file
        /// \param length length of the movie
        Film(std::string name, std::string fileName, unsigned int length) : Video (name, fileName, length) {}


        /// \brief Constructor
        /// \param name name of the movie
        /// \param fileName path to the movie file
        /// \param length length of the movie
        /// \param numberOfChapters number of chapters in the movie
        /// \param chapters duration of each chapter of the movie
        Film(std::string name, std::string fileName, unsigned int length, unsigned int numberOfChapters, unsigned int * chapters);


        Film(const Film& original);


        /// \brief Destructor
        ~Film();

        void setChapters(unsigned int numberOfChapters, unsigned int * chapters);

        unsigned int * getChapters() const;

        unsigned int getNumberOfChapters() const;

        /// \brief Prints the instance variables of the movie
        /// \param output the output file, or cout
        void print(std::ostream & output) const override;
};

