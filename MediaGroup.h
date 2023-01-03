#include <list>
#include <memory>
#include "AbstractMedia.h"

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
		std::string _filename{};

	public:
		/**
		 * @brief Construct a new MediaGroup object
		 * 
		 * @param filename 
		*/
		MediaGroup(std::string filename) : std::list<AbstractMediaPtr>(), _filename(filename){};

		/**
		 * @brief Get the name of the multimedia group
		 * 
		 * @return std::string 
		*/
		std::string getName() const { return _filename;}

		/**
		 * @brief Print all the attributes of the multimedia objects in the group
		 * 
		 * @param output 
		*/
		void print(std::ostream & output) const;
};
