#include "ImageRef.hpp"

ImageRef::name& ImageRef::name::operator++(ImageRef::name& a)
{
	if (a == END)
		a = END;
	else
	a = static_cast<name>(static_cast<int>(a)+1);
	
	return a;
}

