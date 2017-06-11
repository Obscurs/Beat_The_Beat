#ifndef CONDUCTOR_HPP
#define CONDUCTOR_HPP

#include "utils.h"

class Conductor {
public:
	Conductor(const std::string& song);
	~Conductor();

	sf::Time getCurrentTimestamp() const;

private:
	sf::Music mSong;
};

#endif