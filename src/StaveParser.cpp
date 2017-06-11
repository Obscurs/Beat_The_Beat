#include "StaveParser.h"

StaveParser::StaveParser(const Conductor& conductor, Stave& stave,
	                     const std::string& file)
	: mConductor(conductor), mStave(stave), mFile(file) {}

StaveParser::~StaveParser() {}

void StaveParser::parse() {
	mStream.open(mFile);
	std::string command;

	mStream >> command;

	if (mStream.is_open()) {
		while (command != "end") {
			readNote();

			mStream >> command;
		}

		mStream.close();
	} else {
		std::cout << "Could not load stave " << mFile << std::endl;
	}
}

void StaveParser::readNote() {
	float readTimestamp;
	sf::Time timestamp;

	mStream >> readTimestamp;
	timestamp = sf::seconds(readTimestamp);

	bool readInput;
	std::vector<bool> inputs;

	for (unsigned int i = 0; i < InputManager::NUM_ACTIONS; ++i) {
		mStream >> readInput;
		inputs.push_back(readInput);
	}

	Note* note = new Note(mStave, mConductor, timestamp, inputs);
	mStave.addNote(note);
}