#include <iostream>
#include <list>
#include "MediaGroup.h"

MediaGroup::~MediaGroup() {
	std::cout << " MediaGroup " << getName() << " destructor" << std::endl;
}

void MediaGroup::print(std::ostream & output) const {
	output << "GROUP : " << getName()<< "     ";
	for (auto & it : *this) it->print(output);
}