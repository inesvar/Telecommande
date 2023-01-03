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
		AbstractMediaPtr findMediaObject(std::string name) const;

		/**
		 * @brief Return a pointer to the group with a given name if it exists
		 * 
		 * @param name 
		 * @return MediaGroupPtr 
		*/
		MediaGroupPtr findMediaGroup(std::string name) const;

		/**
		 * @brief Print all the attributes of a multimedia object with a given name if it exists
		 * 
		 * @param output 
		 * @param name 
		*/
		void printMediaObject(std::ostream & output, std::string name) const;

		/**
		 * @brief Print all the attributes of a multimedia group with a given name if it exists
		 * 
		 * @param output 
		 * @param name 
		*/
		void printMediaGroup(std::ostream & output, std::string name) const;

		/**
		 * @brief Play a multimedia object with a given name if it exists
		 * 
		 * @param name 
		*/
		void playMediaObject(std::string name) const;

		/**
		 * @brief Construct a new multimedia object of type Film, Video or Photo
		 * 
		 * @tparam T 
		 * @param name 
		 * @param filename 
		 * @return std::shared_ptr<T> 
		*/
		template <typename T> std::shared_ptr<T> createNewObject(std::string name, 
							std::string filename);

		/**
		 * @brief Create a Photo object
		 * 
		 * @param name 
		 * @param filename 
		 * @param latitude 
		 * @param longitude 
		 * @return PhotoPtr 
		*/
		PhotoPtr createPhoto(std::string name, std::string filename, float latitude, 
							float longitude);

		/**
		 * @brief Create a Video object
		 * 
		 * @param name 
		 * @param filename 
		 * @param length 
		 * @return VideoPtr 
		*/
		VideoPtr createVideo(std::string name, std::string filename, unsigned int length);	

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
		FilmPtr createFilm(std::string name, std::string filename, unsigned int length, 
							unsigned int numberOfChapters, unsigned int * chapters);	

		/**
		 * @brief Create a Group object
		 * 
		 * @param name 
		 * @return MediaGroupPtr 
		*/
		MediaGroupPtr createGroup(std::string name);	
};
//// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// 