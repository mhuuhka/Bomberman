#include "event.h"
#include "SFML\Graphics.hpp"

// Oletuskonstruktori ja -destruktori
Event::Event() {}
Event::~Event() {}

// Tapahtumien kasittely pelin aikana
void Event::kasittele(sf::RenderWindow & window) {
	sf::Event tapahtuma;
	while (window.pollEvent(tapahtuma))
	{
		if (tapahtuma.type == sf::Event::Closed) { // Suljetaan ikkuna oikean ylakulman x:sta
			window.close();
		}

		// Suljetaan ESC-nappaimella:
		if ((tapahtuma.type == sf::Event::KeyPressed) && (tapahtuma.key.code == sf::Keyboard::Escape)) {
			window.close();
		}
	}
}