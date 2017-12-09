/*
  ==============================================================================

    Room.cpp
    Created: 9 May 2017 8:28:29pm
    Author:  Zachary

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Room.h"

//==============================================================================
Room::Room()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
	addAndMakeVisible(audience);
	addAndMakeVisible(source);

}

Room::~Room()
{
}

void Room::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::white);
    g.setFont (14.0f);
    g.drawText ("Room", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void Room::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
	float compWidth = 100;
	float compHeight = 100;
	Point<float> sourceOrigin;
	Point<float> audienceOrigin;
	sourceOrigin.x = 300;
	sourceOrigin.y = 200;
	audienceOrigin.x = 100;
	audienceOrigin.y = 100;

	source.setBounds(sourceOrigin.x - compWidth / 2, sourceOrigin.y - compHeight / 2, compWidth, compHeight);
	audience.setBounds(audienceOrigin.x - compWidth / 2, audienceOrigin.y - compHeight / 2, compWidth, compHeight);

}
