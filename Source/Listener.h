/*
  ==============================================================================

    Listener.h
    Created: 9 May 2017 8:27:33pm
    Author:  Zachary

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class Listener    : public Component
{
public:
    Listener();
    ~Listener();

    void paint (Graphics&) override;
    void resized() override;

	void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
		const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)
	{
		const float radius = jmin(width / 2, height / 2) - 4.0f;
		const float centreX = x + width * 0.5f;
		const float centreY = y + height * 0.5f;
		const float rx = centreX - radius;
		const float ry = centreY - radius;
		const float rw = radius * 2.0f;
		const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
		
		g.setColour(Colours::forestgreen);
		g.fillEllipse(rx, ry, rw, rw);

		Path p;
		const float pointerLength = radius *.33f;
		const float pointerThickness = 3.0f;
		p.addRectangle(-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
		p.applyTransform(AffineTransform::rotation(angle).translated(centreX, centreY));

		g.setColour(Colours::darkblue);
		g.fillPath(p);
	}

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Listener);

	Point<float> leftEarPos;
	Point<float> rightEarPos;
	Slider volume; //listening volume
};
