#include "MediaIndex.h"


AbstractMediaPtr MediaIndex::findMediaObject(const std::string & name) const{
	auto it = _mediaObjects.find(name);
	if(it != _mediaObjects.end()){
		return it->second;
	}
	throw std::runtime_error(name +" wasn't  found");
}

MediaGroupPtr MediaIndex::findMediaGroup(const std::string & name) const{
	auto it = _groups.find(name);
	if(it != _groups.end()){
		return it->second;
	}
	throw std::runtime_error(name +" wasn't  found");
}

void MediaIndex::printMediaObject(std::ostream & output, const std::string & name) const{
	findMediaObject(name)->print(output);
}

void MediaIndex::printMediaGroup(std::ostream & output, const std::string & name) const{
	findMediaGroup(name)->print(output);
}

void MediaIndex::playMediaObject(const std::string & name) const{
	findMediaObject(name)->play();
}

void MediaIndex::eraseMediaObject(const std::string & name) {
	try {
		AbstractMediaPtr am = findMediaObject(name);
		for(auto const &g : _groups) {
			g.second->remove(am);
		}
		_mediaObjects.erase(name);
		return;
	} catch (std::exception &e) { //only the findMediaObject can throw an exception
		throw std::runtime_error("No file named "+name+" exists");
	}
}

void MediaIndex::eraseMediaGroup(const std::string & name) {
	try {
		MediaGroupPtr am = findMediaGroup(name);
		_groups.erase(name);
		return;
	} catch (std::exception &e) { //only the findMediaObject can throw an exception
		throw std::runtime_error("No group named "+name+" exists");
	}
}

PhotoPtr MediaIndex::createPhoto(const std::string & name, const std::string & filename, float latitude, float longitude){
	PhotoPtr newPtr = std::make_shared<Photo>(name, filename, latitude, longitude);
	_mediaObjects[name] = newPtr; 
	return newPtr;
}

VideoPtr MediaIndex::createVideo(const std::string & name, const std::string & filename, unsigned int length){
	VideoPtr newPtr = std::make_shared<Video>(name, filename, length);
	_mediaObjects[name] = newPtr; 
	return newPtr;
}

FilmPtr MediaIndex::createFilm(const std::string & name, const std::string & filename, unsigned int length, unsigned int numberOfChapters, unsigned int * chapters){
	FilmPtr newPtr = std::make_shared<Film>(name, filename, length, numberOfChapters, chapters);
	_mediaObjects[name] = newPtr; 
	return newPtr;
}

MediaGroupPtr MediaIndex::createGroup(const std::string & name){
	if (_groups.count(name) > 0) {
		throw std::runtime_error("A group named "+name+" already exists");
		return nullptr;
	}
	MediaGroupPtr newPtr = std::make_shared<MediaGroup>(name);
	_groups[name] = newPtr; 
	return newPtr;
}