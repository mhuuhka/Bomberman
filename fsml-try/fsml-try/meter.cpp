#include "globals.h"
#include "meter.h"
#include <string>
#include "SFML\Graphics.hpp"

// Oletuskonstruktori ja -destruktori
Meter::Meter() {}
Meter::~Meter() {}

// hahmon luonti
Meter::Meter(int r, int g, int b) {
	this->setSize(sf::Vector2f(14, 412));
	this->setFillColor(sf::Color(r, g, b));
	this->setOutlineThickness(2);
	this->setOutlineColor(sf::Color(255, 255, 255));
}

void Meter::draw(sf::RenderWindow & window) {
	window.draw(*this);
}