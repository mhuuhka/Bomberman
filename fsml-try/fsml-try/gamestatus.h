#ifndef gamestatush
#define gamestatush

class Gamestatus {
private:
	int gamestatus;
public:
	Gamestatus();
	~Gamestatus();
	int getgamestatus();
	void setgamestatus(int);	// Asettaa gamestatuksen: [0|1]
};

#endif