/*
  ==============================================================================

    DaKog_LookAndFeel.h
    Created: 4 Nov 2022 7:14:06pm
    Author:  DarKeN

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class DaKog_LookandFeel : public juce::LookAndFeel_V4
{
public:
    //==============================================================================
    DaKog_LookandFeel();
    ~DaKog_LookandFeel() override {};

    void drawRotarySlider(juce::Graphics&, int x, int y, int width, int height,
        float sliderPosProportional, float rotaryStartAngle,
        float rotaryEndAngle, juce::Slider&) override;


private:
    static const char* rotor_png;
    static const int rotor_pngSize;
    juce::Image cachedImage_Rotor_png_1;
    juce::AffineTransform m_ImgTransform;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DaKog_LookandFeel)
};
