/*
  ==============================================================================

    AudioSrc.h
    Created: 9 May 2017 8:28:18pm
    Author:  Zachary

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "AltLook.h"

//==============================================================================
/*
*/
class AudioSrc    : public Component
{
public:
    AudioSrc();
    ~AudioSrc();

    void paint (Graphics&) override;
    void resized() override;

	void mouseDown (const MouseEvent& e) override
	{
		dragger.startDraggingComponent (this, e);
	}

	void mouseDrag (const MouseEvent& e) override
	{
		dragger.dragComponent (this, e, nullptr);
	}

	void updateValues(); //updates all values - called on drag
	void getPosition(float &x, float &y); //returns x and y position

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioSrc);
	float posx;
	float posy;
	Slider volume;
	float lEarDist;
	float rEarDist;
	float lEarVol;
	float rEarVol;
	float lEarDelay;
	float rEarDelay;
	float reverbSend;

	ComponentDragger dragger; //to drag component

	AltLook altLook; //instance of alt style

};
