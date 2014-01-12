#ifndef ANGLE_H
#define ANGLE_H

#include <cmath>

const float PI = 3.141592653f;

class Angle
{
public:
	Angle();
	Angle(const float&);
	
	Angle operator+(const Angle& b);
	Angle operator-(const Angle& b);
	Angle operator*(const Angle& b);
	Angle operator/(const Angle& b);
	
	Angle& operator+=(const Angle& b);
	Angle& operator-=(const Angle& b);
	Angle& operator*=(const Angle& b);
	Angle& operator/=(const Angle& b);
	
	operator float() { return asRadians(); }
	
	float asDegrees() const;
	float asRadians() const;
private:
	float a;
};

#endif //ANGLE_H