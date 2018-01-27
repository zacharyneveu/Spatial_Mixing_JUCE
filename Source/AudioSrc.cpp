/*
  ==============================================================================

    AudioSrc.cpp
    Created: 9 May 2017 8:28:18pm
    Author:  Zachary

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioSrc.h"

//==============================================================================
AudioSrc::AudioSrc()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    volume.setSliderStyle(Slider::Rotary);
    volume.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    volume.setLookAndFeel(&altLook);
    addAndMakeVisible(volume);

    // Initialize icon
    speakerIcon = ImageCache::getFromMemory(Images::source_png, Images::source_pngSize);
}

AudioSrc::~AudioSrc()
{
}

void AudioSrc::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */
    // clear the background
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   

    //Fill circle
    g.setColour (Colours::lightblue);
	g.fillEllipse(0, 0, getWidth(), getHeight());

    //paint text
    g.setColour (Colours::grey);
    g.setFont (24.0f);
    g.drawImage(speakerIcon, 25, 25, 50, 50, 0, 0, 512, 512);
}

void AudioSrc::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

	Rectangle<int> area (getLocalBounds());
	volume.setBounds(getLocalBounds().reduced(area.getWidth()/8, area.getHeight()/8));
}
