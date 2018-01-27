/*
  ==============================================================================

    Listener.h
    Created: 9 May 2017 8:27:33pm
    Author:  Zachary

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "AltLook.h"

//==============================================================================
/*
*/
class Listener : public Component
{
  public:
	Listener();
	~Listener();

	void paint(Graphics &) override;
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
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Listener);

	Point<float> leftEarPos;
	Point<float> rightEarPos;
	Slider volume; //listening volume
	AltLook altLook; //include style instance

	ComponentDragger dragger; //to drag component
};
