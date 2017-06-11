#include "Conductor.h"

Conductor::Conductor(const std::string& song) {
	if (mSong.openFromFile(song) == true)
		mSong.play();
}

Conductor::~Conductor() {}

sf::Time Conductor::getCurrentTimestamp() const {
	return mSong.getPlayingOffset();
}