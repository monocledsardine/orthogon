#ifndef ANGLE_H
#define ANGLE_H

#include <cmath.h>

class Angle
{
public:
	Angle();
	Angle(const float&);
	
	Angle operator+(Angle b);
	Angle operator-(Angle b);
	Angle operator*(Angle b);
	Angle operator/(Angle b);
	
	operator float() { return asRadians(); }
	
	float asDegrees();
	float asRadians();
private:
	float a;
};

#endif //ANGLE_H