#ifndef characterh
#define characterh
#include <string>
#include "SFML\Graphics.hpp"
class Character : public sf::RectangleShape {
protected:
	int points;
	int wins;

public:
	Character();
	~Character();
	Character(std::string, int, sf::Texture *);  // Luo hahmo
	void draw(sf::RenderWindow &);
	void setpoints(int);
	int getpoints();
	void setwins(int);
	int getwins();
};
#endif