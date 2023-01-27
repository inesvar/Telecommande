#include <list>
#include <memory>
#include "AbstractMedia.h"

#ifndef MEDIA_GROUP
#define MEDIA_GROUP

typedef std::shared_ptr<AbstractMedia> AbstractMediaPtr;

/**
 * @brief Represents a group of multimedia objects
 * 
*/
class MediaGroup : public std::list<AbstractMediaPtr> {

	private:
		/**
		 * @brief Name of the group
		 * 
		*/
		std::string _name{};

	public:
		/**
		 * @brief Construct a new MediaGroup object
		 * 
		 * @param filename 
		*/
		MediaGroup(const std::string & name) : std::list<AbstractMediaPtr>(), _name(name){};

		/**
		 * @brief Destruct a MediaGroup object
		*/
		~MediaGroup();

		/**
		 * @brief Get the name of the multimedia group
		 * 
		 * @return const std::string & 
		*/
		const std::string & getName() const { return _name;}

		/**
		 * @brief Print all the attributes of the multimedia objects in the group
		 * 
		 * @param output 
		*/
		void print(std::ostream & output) const;

		/**
         * @brief Returns the name of the class
         * 
         * @return const std::string& 
         */
        void classname(std::ostream & file) const;

        /**
         * @brief Save a multimedia group to a file
         * 
         * @param file 
         */
        void save(std::ostream & file) const;
};

#endif
