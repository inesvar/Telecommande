#include <iostream>
#include <list>
#include "MediaGroup.h"


void MediaGroup::print(std::ostream & output) const {
	output << "GROUP : " << getName() << std::endl;
	for (auto & it : *this) it->print(output);
}