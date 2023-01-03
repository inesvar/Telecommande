#include "MediaIndex.h"


AbstractMediaPtr MediaIndex::findMediaObject(std::string name) const{
	auto it = _mediaObjects.find(name);
	if(it != _mediaObjects.end()){
		return it->second;
	}
	throw std::runtime_error("Media object not found" + name);
}

MediaGroupPtr MediaIndex::findMediaGroup(std::string name) const{
	auto it = _groups.find(name);
	if(it != _groups.end()){
		return it->second;
	}
	throw std::runtime_error("Media group not found" + name);
}

void MediaIndex::printMediaObject(std::ostream & output, std::string name) const{
	findMediaObject(name)->print(output);
}

void MediaIndex::printMediaGroup(std::ostream & output, std::string name) const{
	findMediaGroup(name)->print(output);
}

void MediaIndex::playMediaObject(std::string name) const{
	findMediaObject(name)->play();
}

template <typename T> std::shared_ptr<T> MediaIndex::createNewObject(
					std::string name, std::string filename){
	
	AbstractMediaPtr newPtr = std::make_shared<T>(name, filename);
	_mediaObjects[name] = newPtr; 
	return newPtr;
}

PhotoPtr MediaIndex::createPhoto(std::string name, std::string filename, float latitude, float longitude){
	PhotoPtr newPtr = std::make_shared<Photo>(name, filename, latitude, longitude);
	_mediaObjects[name] = newPtr; 
	return newPtr;
}

VideoPtr MediaIndex::createVideo(std::string name, std::string filename, unsigned int length){
	VideoPtr newPtr = std::make_shared<Video>(name, filename, length);
	_mediaObjects[name] = newPtr; 
	return newPtr;
}

FilmPtr MediaIndex::createFilm(std::string name, std::string filename, unsigned int length, unsigned int numberOfChapters, unsigned int * chapters){
	FilmPtr newPtr = std::make_shared<Film>(name, filename, length, numberOfChapters, chapters);
	_mediaObjects[name] = newPtr; 
	return newPtr;
}

MediaGroupPtr MediaIndex::createGroup(std::string name){
	MediaGroupPtr newPtr = std::make_shared<MediaGroup>(name);
	_groups[name] = newPtr; 
	return newPtr;
}