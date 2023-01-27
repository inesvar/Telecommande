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
        std::string _filename{};

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
         * @param filename Path to the multimedia object
        */
        AbstractMedia(const std::string &name, const std::string &filename) : 
                    _name(name), _filename(filename) {}
        
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
         * @return const std::string & _filename
        */
        const std::string & getfilename() const {return _filename;}

        /**
         * @brief Sets the name of the multimedia object
         * 
         * @param name 
        */
        void setName(const std::string & name) {_name = name;}

        /**
         * @brief Sets the path to the multimedia file
         * 
         * @param filename 
        */
        void setfilename(const std::string & filename) {_filename = filename;}

        /**
         * @brief Prints the instance variables (_name and _filename)
         * 
         * @param output 
        */
        virtual void print(std::ostream & output) const;

        /**
         * @brief Opens the multimedia file
         * 
        */
        virtual void play() const = 0;

        /**
         * @brief Returns the name of the class
         * 
         * @return const std::string& 
         */
        virtual void classname(std::ostream & file) const = 0;

        /**
         * @brief Save a multimedia object to a file
         * 
         * @param file 
         */
        virtual void save(std::ostream & file) const {file << _name << " " << _filename;};

        /**
         * @brief Restore a multimedia object from a file
         * 
         * @param file 
         */
        virtual void restore(std::istream & file) {file >> _name >> _filename;};
};

#endif 