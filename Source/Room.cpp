/*
  ==============================================================================

    Room.cpp
    Created: 9 May 2017 8:28:29pm
    Author:  Zachary

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Room.h"

#define COMP_SIZE 100 //Size of child components in pixels

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
}

void Room::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
	Point<float> sourceOrigin;
	Point<float> audienceOrigin;
	sourceOrigin.x = 300;
	sourceOrigin.y = 200;
	audienceOrigin.x = 100;;
	audienceOrigin.y = 100;

	source.setBounds(sourceOrigin.x - COMP_SIZE / 2, sourceOrigin.y - COMP_SIZE / 2, COMP_SIZE, COMP_SIZE);
	audience.setBounds(audienceOrigin.x - COMP_SIZE / 2, audienceOrigin.y - COMP_SIZE / 2, COMP_SIZE, COMP_SIZE);

}
