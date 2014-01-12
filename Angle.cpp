#include "Angle.h"

Angle::Angle()
{
}

Angle::Angle(const float& b)
{
	a = b;
}

float Angle::asDegrees() const
{
	return 180.0f*a / PI;
}

float Angle::asRadians() const
{
	return a;
}

Angle Angle::operator+(const Angle& b)
{
	return a + b.a;
}

Angle Angle::operator-(const Angle& b)
{
	return a - b.a;
}

Angle Angle::operator*(const Angle& b)
{
	return a * b.a;
}

Angle Angle::operator/(const Angle& b)
{
	return a / b.a;
}

Angle& Angle::operator+=(const Angle& b)
{
	a = *this + b;
	return *this;
}

Angle& Angle::operator-=(const Angle& b)
{
	a =  *this - b;
	return *this;
}

Angle& Angle::operator*=(const Angle& b)
{
	a = *this * b;
	return *this;
}

Angle& Angle::operator/=(const Angle& b)
{
	a = *this / b;
	return *this;
}