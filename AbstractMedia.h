#ifndef ABSTRACT_MEDIA
#define ABSTRACT_MEDIA

#include <string>
#include <iostream>

/**
 * @brief AbstractMedia can represent a video, a photo or a movie...
 * 
*/
class AbstractMedia {

    private:
        /**
         * @brief Name of the multimedia object
         * 
        */
        std::string _name{};
        
        /**
         * @brief Path to the multimedia file
         * 
        */
        std::string _fileName{};

    public:
        /**
         * @brief Constructs a new Abstract Media object
         * 
        */
        AbstractMedia() {}

        /**
         * @brief Constructs a new Abstract Media object
         * 
         * @param name Name of the multimedia object
         * @param fileName Path to the multimedia object
        */
        AbstractMedia(const std::string &name, const std::string &fileName) : 
                    _name(name), _fileName(fileName) {}
        
        /**
         * @brief Destroys the Abstract Media object
         * 
        */
        virtual ~AbstractMedia() {std::cout << "AbstractMedia " 
                    << _name << " destructor" << std::endl << std::endl;}

        /**
         * @brief Gets the name of the multimedia object
         * 
         * @return const std::string &_name
        */
        const std::string &getName() const {return _name;}

        /**
         * @brief Gets the path to the multimedia object
         * 
         * @return const std::string & _fileName
        */
        const std::string & getFileName() const {return _fileName;}

        /**
         * @brief Sets the name of the multimedia object
         * 
         * @param name 
        */
        void setName(const std::string & name) {_name = name;}

        /**
         * @brief Sets the path to the multimedia file
         * 
         * @param fileName 
        */
        void setFileName(const std::string & fileName) {_fileName = fileName;}

        /**
         * @brief Prints the instance variables (_name and _fileName)
         * 
         * @param output 
        */
        virtual void print(std::ostream & output) const;

        /**
         * @brief Opens the multimedia file
         * 
        */
        virtual void play() const = 0;
};

#endif 