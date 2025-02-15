#include "utility.h"

#include <stdlib.h>

double randomDouble()
{
	return static_cast<double>( (static_cast<double>(std::rand())) / (static_cast<double>(RAND_MAX)));
}
