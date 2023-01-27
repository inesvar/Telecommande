#include <map>
#include <memory>
#include "AbstractMedia.h"
#include "MediaGroup.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"

typedef std::shared_ptr<AbstractMedia> AbstractMediaPtr;
typedef std::shared_ptr<MediaGroup> MediaGroupPtr;
typedef std::shared_ptr<Photo> PhotoPtr;
typedef std::shared_ptr<Video> VideoPtr;
typedef std::shared_ptr<Film> FilmPtr;

/**
 * @brief The index allows to manipulate all the multimedia objects and groups
 * 
*/
class MediaIndex {
	private :
		/**
		 * @brief All multimedia objects
		 * 
		*/
		std::map<std::string, AbstractMediaPtr> _mediaObjects{};

		/**
		 * @brief All groups of multimedia objects
		 * 
		*/
		std::map<std::string, MediaGroupPtr> _groups{};

	public :

		/**
		 * @brief Return a pointer to the object with a given name if it exists
		 * 
		 * @param name 
		 * @return AbstractMediaPtr 
		*/
		AbstractMediaPtr findMediaObject(const std::string & name) const;

		/**
		 * @brief Return a pointer to the group with a given name if it exists
		 * 
		 * @param name 
		 * @return MediaGroupPtr 
		*/
		MediaGroupPtr findMediaGroup(const std::string & name) const;

		/**
		 * @brief Print all the attributes of a multimedia object with a given name if it exists
		 * 
		 * @param output 
		 * @param name 
		*/
		void printMediaObject(std::ostream & output, const std::string & name) const;

		/**
		 * @brief Print all the attributes of a multimedia group with a given name if it exists
		 * 
		 * @param output 
		 * @param name 
		*/
		void printMediaGroup(std::ostream & output, const std::string & name) const;

		/**
		 * @brief Play a multimedia object with a given name if it exists
		 * 
		 * @param name 
		*/
		void playMediaObject(const std::string & name) const;

		/**
		 * @brief Erase a multimedia object with a given name if it exists
		 * 
		 * @param name 
		*/
		void eraseMediaObject(const std::string & name);

		/**
		 * @brief Erase a multimedia group with a given name if it exists
		 * 
		 * @param name 
		*/
		void eraseMediaGroup(const std::string & name);

		/**
		 * @brief Construct a new multimedia object of type Film, Video or Photo
		 * 
		 * @tparam T 
		 * @param name 
		 * @param filename 
		 * @return std::shared_ptr<T> 
		*/
		template <typename T> std::shared_ptr<T> createNewObject(const std::string & name, 
							const std::string & filename) {
								if (_mediaObjects.count(name) > 0) {
									throw std::runtime_error("A media object named "+name+" already exists");
									return nullptr;
								}
								auto newPtr = std::make_shared<T>(name, filename);
								_mediaObjects[name] = newPtr; 
								return newPtr;
							};

		/**
		 * @brief Create a Photo object
		 * 
		 * @param name 
		 * @param filename 
		 * @param latitude 
		 * @param longitude 
		 * @return PhotoPtr 
		*/
		PhotoPtr createPhoto(const std::string & name, const std::string & filename, float latitude, 
							float longitude);

		/**
		 * @brief Create a Video object
		 * 
		 * @param name 
		 * @param filename 
		 * @param length 
		 * @return VideoPtr 
		*/
		VideoPtr createVideo(const std::string & name, const std::string & filename, unsigned int length);	

		/**
		 * @brief Create a Film object
		 * 
		 * @param name 
		 * @param filename 
		 * @param length 
		 * @param numberOfChapters 
		 * @param chapters 
		 * @return FilmPtr 
		*/
		FilmPtr createFilm(const std::string & name, const std::string & filename, unsigned int length, 
							unsigned int numberOfChapters, unsigned int * chapters);	

		/**
		 * @brief Create a Group object
		 * 
		 * @param name 
		 * @return MediaGroupPtr 
		*/
		MediaGroupPtr createGroup(const std::string & name);
};
//// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// 