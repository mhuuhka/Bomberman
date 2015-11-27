#pragma once
#ifndef tekstih
#define tekstih
#include <string>
#include "SFML\Graphics.hpp"
class Teksti : public sf::Text {
protected:
	std::string textcontent;
public:
	Teksti();
	~Teksti();
	Teksti(sf::Font *, int, int, int, int, std::string);  // Luo teksti
	void draw(sf::RenderWindow &);
	void setteksti(std::string);
	std::string getteksti();
};
#endif