#include "Conductor.h"

Conductor::Conductor(const std::string& song) {
	if (mInputStream.open(song) == false) {
		std::cout << "Failed to load song " << song << std::endl;
	} else {
		mSong.openFromStream(mInputStream);
		mSong.play();
	}
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