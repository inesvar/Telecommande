#include <iostream>
#include <list>
#include "MediaGroup.h"


void MediaGroup::print(std::ostream & output) const {
	for (auto & it : *this) it->print(std::cout);
}