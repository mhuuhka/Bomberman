#include "teksti.h"
#include <string>
#include "SFML\Graphics.hpp"

// Oletuskonstruktori ja -destruktori
Teksti::Teksti() {}
Teksti::~Teksti() {}

// Tekstin luonti
Teksti::Teksti(sf::Font * font, int r = 255, int g = 255, int b = 0, int fsize = 14, std::string str = "") {
	//sf::Font font;
	font->loadFromFile("tahoma.ttf");
	this->setFont(*font);
	this->setStyle(sf::Text::Bold);
	this->setCharacterSize(fsize);
	this->setColor(sf::Color(r, g, b));
	this->setString(str);
}

void Teksti::draw(sf::RenderWindow & window) {
	window.draw(*this);
}

void Teksti::setteksti(std::string s) {
	this->textcontent = s;
}

std::string Teksti::getteksti() {
	return this->textcontent;
}