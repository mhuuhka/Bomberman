#include "gamestatus.h"	

// Peli kaynnissa: status=1
// Oletuskonstruktori ja -destruktori
Gamestatus::Gamestatus() {
	this->gamestatus = 0;
}

Gamestatus::~Gamestatus() {}

int Gamestatus::getgamestatus() {
	return this->gamestatus;
}

void Gamestatus::setgamestatus(int gs) {
	this->gamestatus = gs;
}