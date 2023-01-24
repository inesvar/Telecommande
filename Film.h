#include "AbstractMedia.h"
#include "Video.h"
#include <iostream>


#ifndef FILM
#define FILM

/**
 * @brief Film class : each film has a length, several chapters (also with a length)
 * 
*/
class Film : public Video {

    private:
        /**
         * @brief Duration of each chapter of the movie (integral values)
         * 
        */
        unsigned int * _chapters{};

        /**
         * @brief Number of chapters in the movie
         * 
        */
        unsigned int _numberOfChapters{};

    public:
        /**
         * @brief Constructs a new Film object
         * 
        */
        Film() {}

        /**
         * @brief Construct a new Film object
         * 
         * \param name name of the file
         * \param filename path to the file
         * 
        */
        Film(const std::string & name, const std::string & filename) : Video(name, filename) {};

        /**
         * @brief Constructs a new Film object
         * 
         * @param name of the movie
         * @param filename path to the movie file
         * @param length of the movie
        */
        Film(const std::string & name, const std::string & filename, 
                    unsigned int length) : Video (name, filename, length) {}
        
        /**
         * @brief Constructs a new Film object
         * 
         * @param name of the movie
         * @param filename path to the movie file
         * @param length of the movie
         * @param numberOfChapters 
         * @param chapters duration of each chapter
        */
        Film(const std::string & name, const std::string & filename, 
                    unsigned int length, unsigned int numberOfChapters, 
                    unsigned int * chapters);

        /**
         * @brief Constructs a new Film object by making a deepcopy
         * 
         * @param original the Film copied
        */
        Film(const Film& original);


        /**
         * @brief Destroys the Film object
         * 
        */
        ~Film();

        /**
         * @brief Sets the durations of the chapters
         * 
         * @param numberOfChapters 
         * @param chapters pointer to an array containing the durations 
         * (integral values)
        */
        void setChapters(unsigned int numberOfChapters, unsigned int * chapters);

        /**
         * @brief Gets the durations of all the chapters
         * 
         * @return unsigned int* array, the number of chapters is given 
         * by the first element
        */
        unsigned int * getChapters() const;

        /**
         * @brief Gets the number of chapters
         * 
         * @return unsigned int 
        */
        unsigned int getNumberOfChapters() const;

        /**
         * @brief Prints all the instance variables
         * 
         * @param output std::cout or other
        */
        void print(std::ostream & output) const override;
};

#endif
