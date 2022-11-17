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

    void drawLinearSlider(juce::Graphics& g, int x, int y, int width, int height,
        float sliderPos,
        float minSliderPos,
        float maxSliderPos,
        const juce::Slider::SliderStyle style, juce::Slider& slider) override;

    void drawPointer(juce::Graphics& g, const float x, const float y, const float diameter,
        const juce::Colour& colour, const int direction) noexcept;

    int getSliderThumbRadius(juce::Slider& slider) override;

        //juce::Label* createSliderTextBox(juce::Slider& slider) override;
        //juce::Slider::SliderLayout getSliderLayout(juce::Slider& slider) override;


private:
    static const char* rotor_png;
    static const int rotor_pngSize;
    juce::Image cachedImage_Rotor_png_1;
    juce::AffineTransform m_ImgTransform;
    juce::AffineTransform m_ImgTransform2;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DaKog_LookandFeel)
};
