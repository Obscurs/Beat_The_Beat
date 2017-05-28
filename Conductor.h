#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include "Utils.h"

class Conductor {
public:
	Conductor(const std::string& song);
	~Conductor();
	void stopSong();
	sf::Time getCurrentTimestamp() const;

private:
	sf::FileInputStream mInputStream;
	sf::Music mSong;
};

#endif