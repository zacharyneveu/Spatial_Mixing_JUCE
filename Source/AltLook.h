/*
  ==============================================================================

    AltLook.h
    Created: 26 Jan 2018 9:18:25pm
    Author:  zach

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class AltLook : public LookAndFeel_V4
{
public:
  AltLook()
  {
  }

  void drawRotarySlider(Graphics &g, int x, int y, int width, int height, float sliderPos,
                        const float rotaryStartAngle, const float rotaryEndAngle, Slider &slider)
  {
    const float radius = jmin(width / 2, height / 2);
    const float centreX = x + width * 0.5f;
    const float centreY = y + height * 0.5f;
    const float rx = centreX - radius;
    const float ry = centreY - radius;
    const float rw = radius * 2.0f;
    const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);

    g.setColour(Colours::forestgreen);
    g.fillEllipse(rx, ry, rw, rw);

    Path p;
    const float pointerLength = radius * .33f;
    const float pointerThickness = 12.0f;
    p.addRectangle(-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
    p.applyTransform(AffineTransform::rotation(angle).translated(centreX, centreY));

    g.setColour(Colours::darkblue);
    g.fillPath(p);
  }
};