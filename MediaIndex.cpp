#include <fstream>
#include <iostream>
#include "MediaIndex.h"


AbstractMediaPtr MediaIndex::findMediaObject(const std::string & name) const{
	auto it = _mediaObjects.find(name);
	if(it != _mediaObjects.end()){
		return it->second;
	}
	throw std::runtime_error(name +" wasn't found");
}

MediaGroupPtr MediaIndex::findMediaGroup(const std::string & name) const{
	auto it = _groups.find(name);
	if(it != _groups.end()){
		return it->second;
	}
	throw std::runtime_error(name +" wasn't found");
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
	} catch (std::exception &e) { //only the findMediaObject can throw an exception, if the file doesn't exist
		throw std::runtime_error("No file named "+name+" exists");
	}
}

void MediaIndex::eraseMediaGroup(const std::string & name) {
	try {
		MediaGroupPtr am = findMediaGroup(name);
		_groups.erase(name);
		return;
	} catch (std::exception &e) { //only the findMediaObject can throw an exception, if the group doesn't exist
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

void MediaIndex::save(const std::string & filename) {
	std::ofstream f;
	f.open(filename);
	if (!f) {
		throw std::runtime_error("Can't open file "+ filename);
	}
	for (auto it : _mediaObjects) {
		it.second->classname(f);
		it.second->save(f); 
		f << std::endl;
		if (f.fail()) {
			throw std::runtime_error("Can't write to file "+ filename);
		} 
	}
	for (auto it : _groups) {
		it.second->classname(f);
		it.second->save(f); 
		f << std::endl;
		if (f.fail()) {
			throw std::runtime_error("Can't write to file "+ filename);
		} 
	}
	f.close();
}

void MediaIndex::read(const std::string & filename) {
	std::ifstream f;
	f.open(filename);
	if (!f) {
		throw std::runtime_error("Can't open file "+ filename);
	}
	while (f) {          
		std::string classname;
		getline(f, classname);

		if (classname == "Photo") {
			PhotoPtr obj = std::make_shared<Photo>();
			obj->restore(f);
			if (f.fail()) {                       
				throw std::runtime_error("Can't read from file "+ filename);
			} 
			_mediaObjects[obj->getName()] = obj;
		}
		else if (classname == "Video") {
			VideoPtr obj = std::make_shared<Video>();
			obj->restore(f);
			if (f.fail()) {                       
				throw std::runtime_error("Can't read from file "+ filename);
			} 
			_mediaObjects[obj->getName()] = obj;
		}
		else if (classname == "Film") {
			FilmPtr obj = std::make_shared<Film>();
			obj->restore(f);
			if (f.fail()) {                       
				throw std::runtime_error("Can't read from file "+ filename);
			} 
			_mediaObjects[obj->getName()] = obj;
		} else if (classname == "Group") {
			std::string name;
			f >> name;
			MediaGroupPtr obj = std::make_shared<MediaGroup>(name);
			unsigned int numberOfObjects;
			f >> numberOfObjects;
			for (unsigned int i = 0; i < numberOfObjects; i++) {
				f >> name;
				obj->push_back(findMediaObject(name));
			}

			if (f.fail()) {                       
				throw std::runtime_error("Can't read from file "+ filename);
			} 
			_groups[obj->getName()] = obj;
		} 
		else {
			throw std::runtime_error("Unknown class "+ classname);
		}
		getline(f, classname); // on passe a la ligne suivante
	}
	f.close();
}

void MediaIndex::print(std::ostream & output) const{
	for (auto it : _mediaObjects) {
		it.second->print(output);
	}
	for (auto it : _groups) {
		it.second->print(output);
	}
}

void MediaIndex::erase() {
	_mediaObjects.clear();
	_groups.clear();
}