#include <iostream>
#include <list>
#include "MediaGroup.h"

MediaGroup::~MediaGroup() {
	std::cout << " MediaGroup " << getName() << " destructor" << std::endl;
}

void MediaGroup::print(std::ostream & output) const {
	output << "GROUP : " << getName()<< "    ";
	for (auto & it : *this) {
		output << " " << it->getName();
	};
	output << "                                                                                               ";
}

void MediaGroup::classname(std::ostream & file) const {
	file << "Group" << std::endl;
}

void MediaGroup::save(std::ostream & file) const {
	file << getName() << " " << size();
	for (auto & it : *this) {
		file << " " << it->getName();
	}
}
