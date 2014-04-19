#ifndef VECTORHELPER_H
#define VECTORHELPER_H

#include <SFML/System/Vector2.hpp>
#include <cmath>
//Helper functions for sf::Vector2f

//Dot product
template<typename T> T dot(const sf::Vector2<T>& a, const sf::Vector2<T>& b)
{
	return a.x*b.x + a.y*b.y;
}

//projection onto b
template<typename T> sf::Vector2<T> project(const sf::Vector2<T>& from, const sf::Vector2<T>& onto)
{
	T dotOnto(dot(onto, onto));
	if (dotOnto == 0)
		return sf::Vector2<T>(0,0);
		
	return onto*(dot(from,onto)/dot(onto, onto));
}

template<typename T> T mag(const sf::Vector2<T>& a)
{
	return std::sqrt(a*a);
}

#endif //VECTORHELPER_H