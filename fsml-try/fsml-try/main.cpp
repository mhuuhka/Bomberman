
#include <iostream>
#include <random>
#include "globals.h"
#include "event.h"
#include "gamestatus.h"
#include "character.h"
#include "teksti.h"
#include "meter.h"
#include <math.h>
#include <SFML/Graphics.hpp>

int main() {

	// Satunnaislukujen alustus
	std::random_device rd;
	std::srand(rd());

	// dClock FPS:stä riippumaton peliaika
	sf::Clock dClock;

	// Tausta
	sf::Image background_image;
	background_image.loadFromFile("background.jpg");
	sf::Texture background_tex;
	background_tex.loadFromImage(background_image);
	sf::RectangleShape background;
	background.setSize(sf::Vector2f((float)ag::ZONE_WIDTH, (float)ag::ZONE_HEIGHT));
	background.setPosition(0, 0);
	background.setTexture(&background_tex);

	// Pelin tilan ja tapahtumien kasittely
	Event      tapahtumat;
	Gamestatus pelitila;

	// Hahmot
	sf::Texture vmantex, smantex;
	Character vman("viikatemies.png", -ag::CHARACTER_DISTANCE, &vmantex);
	Character sman("superman.png", ag::CHARACTER_DISTANCE, &smantex);

	// Tekstit
	sf::Font font1, font2, font3, font4;

	Teksti vmantext(&font1, 0, 0, 0, 16, "");
	Teksti smantext(&font2, 0, 0, 255, 16, "");
	vmantext.setPosition(50, ag::ZONE_HEIGHT - 60);
	smantext.setPosition(ag::ZONE_WIDTH - 180, ag::ZONE_HEIGHT - 60);

	Teksti endtext(&font3, 255, 255, 255, 16, "");
	endtext.setPosition(130, 300);

	Teksti total_result_text(&font4, 255, 255, 255, 20, "");
	total_result_text.setPosition(230, ag::ZONE_HEIGHT - 60);

	// Mittarit
	Meter vmanmeter(0, 0, 0);
	Meter smanmeter(255, 0, 0);
	vmanmeter.setPosition(40, 35);
	smanmeter.setPosition(ag::ZONE_WIDTH - 50, 35);

	sf::RenderWindow window(sf::VideoMode(ag::ZONE_WIDTH, ag::ZONE_HEIGHT), "Superman vs. Viikatemies");

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// - - - - - - - - - - - Varsinanen peli kayntiin  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	pelitila.setgamestatus(1);

	while (window.isOpen()) {
		tapahtumat.kasittele(window);

		// Pelinopeus FPS:stä riippumaton vakio
		float d = dClock.restart().asSeconds();
		float siirtyma = d * ag::GAME_SPEED;

		// Peli kaynnissa
		if (pelitila.getgamestatus() == 1)
		{
			// Viikatemiehen siirtyma
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				vman.setPosition(vman.getPosition() + sf::Vector2f(0, -siirtyma));
				vman.setRotation(0);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				vman.setPosition(vman.getPosition() + sf::Vector2f(0, siirtyma));
				vman.setRotation(180);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				vman.setPosition(vman.getPosition() + sf::Vector2f(-siirtyma, 0));
				vman.setRotation(270);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				vman.setPosition(vman.getPosition() + sf::Vector2f(siirtyma, 0));
				vman.setRotation(90);
			}

			// Hahmo ilmestyy alueen toiselta puolelta ylittaessaan rajat
			if (vman.getPosition().x > ag::ZONE_WIDTH + ag::BORDER_LIMIT) vman.setPosition(vman.getPosition() + sf::Vector2f(-siirtyma - 40, 0));
			if (vman.getPosition().x < -ag::BORDER_LIMIT) vman.setPosition(vman.getPosition() + sf::Vector2f(siirtyma + 40, 0));
			if (vman.getPosition().y > ag::ZONE_HEIGHT + ag::BORDER_LIMIT) vman.setPosition(vman.getPosition() + sf::Vector2f(0, -siirtyma - 40));
			if (vman.getPosition().y < -ag::BORDER_LIMIT) vman.setPosition(vman.getPosition() + sf::Vector2f(0, siirtyma + 40));

			// Supermanin siirtyma
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				sman.setPosition(sman.getPosition() + sf::Vector2f(0, -siirtyma));
				sman.setRotation(0);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				sman.setPosition(sman.getPosition() + sf::Vector2f(0, siirtyma));
				sman.setRotation(180);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				sman.setPosition(sman.getPosition() + sf::Vector2f(-siirtyma, 0));
				sman.setRotation(270);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				sman.setPosition(sman.getPosition() + sf::Vector2f(siirtyma, 0));
				sman.setRotation(90);
			}

			// Hahmo ilmestyy alueen toiselta puolelta ylittaessaan rajat
			if (sman.getPosition().x > ag::ZONE_WIDTH + ag::BORDER_LIMIT) sman.setPosition(sman.getPosition() + sf::Vector2f(-siirtyma - 40, 0));
			if (sman.getPosition().x < -ag::BORDER_LIMIT) sman.setPosition(sman.getPosition() + sf::Vector2f(siirtyma + 40, 0));
			if (sman.getPosition().y > ag::ZONE_HEIGHT + ag::BORDER_LIMIT) sman.setPosition(sman.getPosition() + sf::Vector2f(0, -siirtyma - 40));
			if (sman.getPosition().y < -ag::BORDER_LIMIT) sman.setPosition(sman.getPosition() + sf::Vector2f(0, siirtyma + 40));

			// Jos hahmot tormaavat
			if (vman.getPosition().x < sman.getPosition().x + ag::COLLISION_LIMIT &&
				vman.getPosition().x > sman.getPosition().x - ag::COLLISION_LIMIT &&
				vman.getPosition().y < sman.getPosition().y + ag::COLLISION_LIMIT &&
				vman.getPosition().y > sman.getPosition().y - ag::COLLISION_LIMIT)
			{
				// Viikatemiehelle arvotaan uusi sijainti
				float xsijainti = (float)(std::rand() % ag::ZONE_WIDTH + 1);
				float ysijainti = (float)(std::rand() % ag::ZONE_HEIGHT + 1);
				vman.setPosition(xsijainti, ysijainti);

				// Kummankin pisteitä lisätään demotarkoituksessa
				sman.setpoints(sman.getpoints() + 50);
				vman.setpoints(vman.getpoints() + 50);
			}
		} // Peli kaynnissa

		  // Naytetaan pistemaara hahmoille
		vmantext.setString("Viikatemies = " + std::to_string(vman.getpoints()));
		smantext.setString("Superman = " + std::to_string(sman.getpoints()));
		total_result_text.setString(std::to_string(vman.getwins()) + " - " + std::to_string(sman.getwins()));

		// Tyhjataan naytto
		window.clear();

		// Piirrellaan oliot naytolle
		window.draw(background, sf::RenderStates::Default);
		vman.draw(window);
		sman.draw(window);
		vmantext.draw(window);
		smantext.draw(window);
		total_result_text.draw(window);

		// "Pistemittarit"
		vmanmeter.setSize(sf::Vector2f(14, (float)vman.getpoints()));
		smanmeter.setSize(sf::Vector2f(14, (float)sman.getpoints()));
		vmanmeter.draw(window);
		smanmeter.draw(window);

		// Jos jommallakummalla pelaajalla pisteet yli 200, kerrotaan voittaja
		if (vman.getpoints() >= 200)
		{
			if (pelitila.getgamestatus()) vman.setwins(vman.getwins() + 1);
			pelitila.setgamestatus(0);
			endtext.setString("Viikatemies voitti eran!\n  R = Uusi era | ESC = Lopeta");
			endtext.draw(window);
		}
		else if (sman.getpoints() >= 200)
		{
			if (pelitila.getgamestatus()) sman.setwins(sman.getwins() + 1);
			pelitila.setgamestatus(0);
			endtext.setString("     Superman voitti eran!\nR = Uusi era | ESC = Lopeta");
			endtext.draw(window);
		}

		// Pelin uudelleenkaynnistys R:lla
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			vman.setPosition(-ag::CHARACTER_DISTANCE + ag::ZONE_WIDTH / 2, ag::ZONE_HEIGHT / 2);
			sman.setPosition(ag::CHARACTER_DISTANCE + ag::ZONE_WIDTH / 2, ag::ZONE_HEIGHT / 2);
			vman.setpoints(0);
			sman.setpoints(0);
			pelitila.setgamestatus(1);
		}

		window.display();
	}
	return 0;
}