#include "Conductor.h"

Conductor::Conductor(const std::string& song) {
	if (mSong.openFromFile(song) == false)
		std::cout << "Failed to load song " << song << std::endl;
	else
		mSong.play();
}

Conductor::~Conductor() {
	stopSong();
}

sf::Time Conductor::getCurrentTimestamp() const {
	return mSong.getPlayingOffset();
}
void Conductor::stopSong(){

	mSong.stop();
	//mSong.~Music();
}