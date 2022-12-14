/// \file AbstractMedia.h

#ifndef BC
#define BC

#include <string>
#include <iostream>

/// \class AbstractMedia
/// \brief This superclass represents a multimedia object
///
/// \param _name name of the multimedia file
/// \param _fileName path to the mulimedia file
class AbstractMedia {

    private:
        /// \brief name of the multimedia object
        std::string _name{};
        /// \brief path to the multimedia file
        std::string _fileName{};

    public:
        /// \brief Constructor
        AbstractMedia() {}

        /// \brief Constructor
        /// \param name name of the multimedia object
        /// \param fileName path to the multimedia file
        AbstractMedia(std::string name, std::string fileName) : _name(name), _fileName(fileName) {}
        
        /// \brief Destructor
        virtual ~AbstractMedia() {std::cout << "AbstractMedia" << _name << "destructor" << std::endl;}

        /// \brief Getter
        /// \return _name : name of the multimedia object
        std::string getName() const {return _name;}

        /// \brief Getter
        /// \return _fileName : path to the multimedia file
        std::string getFileName() const {return _fileName;}

        /// \brief Setter : changes the name of the multimedia object
        /// \param name new name of the multimedia object
        void setName(std::string name) {_name = name;}

        /// \brief Setter : changes the path to the file
        /// \param fileName new path to the multimedia file
        void setFileName(std::string fileName) {_fileName = fileName;}

        /// \brief Prints _name (name of the multimedia object) 
        /// \brief and _fileName (path to the file) to the chosen output.
        /// \param output
        virtual void print(std::ostream & output) const;

        /// \brief Opens the multimedia file
        virtual void play() const = 0;
};

#endif 