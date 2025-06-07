/////////////////////////////////////////////////
// Modified from:     www.elegoo.com (2017.12.9)
// Modified for:      Team Voltage 386
// Date:              2025/05/16
/////////////////////////////////////////////////
#include <MelodySubsystem.h>

// <<constructor>>
MelodySubsystem::MelodySubsystem()
{
	prevMillis = 0;
	currMillis = 0;

	myPort = 13; // the pin of the active Melody

	// notes in the melody:
	melody[0] = NOTE_C5;
	melody[1] = NOTE_D5;
	melody[2] = NOTE_E5;
	melody[3] = NOTE_F5;
	melody[4] = NOTE_G5;
	melody[5] = NOTE_A5;
	melody[6] = NOTE_B5;
	melody[7] = NOTE_C6;
	melody[8] = NOTE_D6;
	melody[9] = NOTE_E6;

	// sound duration
	soundDuration = 500; // 500 miliseconds
	noteIndex = 0;
}

// <<constructor>>
MelodySubsystem::MelodySubsystem(unsigned int port, unsigned long duration)
{
	prevMillis = 0;
	currMillis = 0;

	myPort = port; // the pin of the active Melody

	// notes in the melody:
	melody[0] = NOTE_C5;
	melody[1] = NOTE_D5;
	melody[2] = NOTE_E5;
	melody[3] = NOTE_F5;
	melody[4] = NOTE_G5;
	melody[5] = NOTE_A5;
	melody[6] = NOTE_B5;
	melody[7] = NOTE_C6;
	melody[8] = NOTE_D6;
	melody[9] = NOTE_E6;

	// sound duration
	soundDuration = duration;
	noteIndex = 0;
}

// Call this in setup() function
void MelodySubsystem::setup()
{
	pinMode(myPort, OUTPUT); // initialize the Melody pin as an output
}

// Call this in loop() function
void MelodySubsystem::loopTune1()
{
	currMillis = millis();

	// if curr - prev is greater or equal to interval, take action
	if (currMillis - prevMillis >= soundDuration)
	{
		// play the tune
		tone(myPort, melody[iNote], soundDuration);

		if (iNote == 7)
		{
			iNote = 0;
		}
		else
		{
			iNote++;
		}

		prevMillis = currMillis;
	}
}

void MelodySubsystem::selectNote(int index)
{
	noteIndex = index;
}

// Call this in loop() function
void MelodySubsystem::loop()
{
	// play the tune
	tone(myPort, melody[noteIndex], soundDuration);
}
