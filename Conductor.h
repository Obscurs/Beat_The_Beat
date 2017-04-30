#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include "Utils.h"

class Conductor {
public:
	Conductor(const std::string& song);
	~Conductor();

	sf::Time getCurrentTimestamp() const;

private:
	sf::Music mSong;
};

#endif