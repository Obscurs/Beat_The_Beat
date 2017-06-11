#ifndef STAVEPARSER_HPP
#define STAVEPARSER_HPP

#include "utils.h"
#include "Conductor.h"
#include "Stave.h"
#include "Note.h"
#include "InputManager.h"

class StaveParser {
public:
	StaveParser(const Conductor& conductor, Stave& stave,
			    const std::string& file);
	~StaveParser();

	void parse();

private:
	const Conductor& mConductor;
	Stave& mStave;
	const std::string mFile;
	std::ifstream mStream;

	void readNote();
};

#endif