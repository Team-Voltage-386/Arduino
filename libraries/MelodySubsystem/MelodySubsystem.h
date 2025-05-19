#ifndef MELODYSUBSYSTEM_H
#define MELODYSUBSYSTEM_H

#include "Arduino.h"
#include "pitches.h"

// class MelodySubsystem
class MelodySubsystem
{
public:
	MelodySubsystem();
	MelodySubsystem(unsigned int port, unsigned long duration);
	void setup();
	void loop();
	void loopTune1();
	void selectNote(int index);

private:
	unsigned long prevMillis;
	unsigned long currMillis;

	int myPort; // the pin of the active Melody

	int soundDuration;
	int iNote;
	int noteIndex;

	int melody[10];
};

#endif
