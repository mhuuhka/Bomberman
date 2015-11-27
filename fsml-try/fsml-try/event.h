#ifndef eventh
#define eventh
#include "SFML\Graphics.hpp"
class Event {
public:
	Event();
	~Event();
	void kasittele(sf::RenderWindow &);  // ikkunan osoite
};
#endif