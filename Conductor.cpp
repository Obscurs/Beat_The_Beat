#include "Conductor.h"

Conductor::Conductor(const std::string& song) {
	if (mSong.openFromFile(song) == false)
		std::cout << "Failed to load song " << song << std::endl;
	else
		mSong.play();
}

Conductor::~Conductor() {
	mSong.stop();
}

sf::Time Conductor::getCurrentTimestamp() const {
	return mSong.getPlayingOffset();
}