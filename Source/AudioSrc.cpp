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

    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::white);
    g.setFont (14.0f);
    g.drawText ("AudioSrc", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void AudioSrc::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
