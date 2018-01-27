/*
  ==============================================================================

    Listener.cpp
    Created: 9 May 2017 8:27:33pm
    Author:  Zachary

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Listener.h"

//==============================================================================
Listener::Listener()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

    volume.setSliderStyle(Slider::Rotary);
    volume.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    volume.setLookAndFeel(&altLook);
	addAndMakeVisible(volume);

    earIcon = ImageCache::getFromMemory(Images::ear_png, Images::ear_pngSize);
}

Listener::~Listener()
{
}

void Listener::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (Colours::lightblue);
	g.fillEllipse(0, 0, getWidth(), getHeight());
    //black outline
    g.setColour (Colours::black);
    int thick = 5;
	g.drawEllipse(thick, thick, getWidth()-2*thick, getHeight()-2*thick, thick);

    g.setColour (Colours::grey);
    g.setFont (24.0f);

    g.drawImage(earIcon, 25, 25, 50, 50, 0, 0, 512, 512);
}

void Listener::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

	Rectangle<int> area (getLocalBounds());
	volume.setBounds(getLocalBounds().reduced(area.getWidth()/8, area.getHeight()/8));
}
