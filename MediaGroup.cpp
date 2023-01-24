#include <iostream>
#include <list>
#include "MediaGroup.h"


void MediaGroup::print(std::ostream & output) const {
	output << "GROUP : " << getName()<< "     ";
	for (auto & it : *this) it->print(output);
}