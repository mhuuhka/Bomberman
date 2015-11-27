#include "globals.h"
#include "character.h"
#include <string>
#include "SFML\Graphics.hpp"

// Oletuskonstruktori ja -destruktori
Character::Character() {}
Character::~Character() {}

// hahmon luonti
Character::Character(std::string imgname, int xpos, sf::Texture * tex) {

	sf::Image img;
	img.loadFromFile(imgname);
	img.createMaskFromColor(sf::Color::White);
	tex->loadFromImage(img);

	this->setSize(sf::Vector2f(64, 64));
	this->setPosition(xpos + ag::ZONE_WIDTH / 2, ag::ZONE_HEIGHT / 2);
	this->setOrigin(32, 32);
	this->setTexture(tex);

	this->setpoints(0);
	this->setwins(0);
}

void Character::draw(sf::RenderWindow & window) {
	window.draw(*this);
}

void Character::setpoints(int n) {
	this->points = n;
}
int Character::getpoints() {
	return this->points;
}
void Character::setwins(int n) {
	this->wins = n;
}

int Character::getwins() {
	return this->wins;
}
