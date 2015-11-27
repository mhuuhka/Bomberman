#pragma once
#ifndef meterh
#define meterh
#include <string>
#include "SFML\Graphics.hpp"
class Meter : public sf::RectangleShape {
protected:

public:
	Meter();
	~Meter();
	Meter(int, int, int);  // Luo mittari
	void draw(sf::RenderWindow &);
};
#endif