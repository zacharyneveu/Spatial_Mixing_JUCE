/*
  ==============================================================================

    Room.h
    Created: 9 May 2017 8:28:29pm
    Author:  Zachary

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioSrc.h"
#include "Listener.h"

//==============================================================================
/*
*/
class Room    : public Component
{
public:
    Room();
    ~Room();

    void paint (Graphics&) override;
    void resized() override;

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Room);
	Listener audience;
	AudioSrc source;
};
