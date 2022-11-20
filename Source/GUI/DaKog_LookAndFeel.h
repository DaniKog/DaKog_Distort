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

    juce::Slider::SliderLayout getSliderLayout(juce::Slider& slider) override;

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

    void drawTickBox(juce::Graphics& g, juce::Component& component,
        float x, float y, float w, float h,
        const bool ticked,
        const bool isEnabled,
        const bool shouldDrawButtonAsHighlighted,
        const bool shouldDrawButtonAsDown) override;

    void drawToggleButton(juce::Graphics& g, juce::ToggleButton& button,
        bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override;

    int getSliderThumbRadius(juce::Slider& slider) override;

        //juce::Label* createSliderTextBox(juce::Slider& slider) override;
        //juce::Slider::SliderLayout getSliderLayout(juce::Slider& slider) override;


private:
    juce::AffineTransform m_ImgTransform;

    static const char* rotor_png;
    static const int rotor_pngSize;
    juce::Image cachedImage_Rotor_png_1;

    static const char* button_middle_off_126_png;
    static const int button_middle_off_126_pngSize;
    juce::Image cachedImage_button_middle_off_126_png_1;
    

    static const char* button_middle_on_126_png;
    static const int button_middle_on_126_pngSize;
    juce::Image cachedImage_button_middle_on_126_png_2;
    

    static const char* fader18_png;
    static const int fader18_pngSize;
    juce::Image cachedImage_fader18_png_1;

    static const char* horizontalFader18_png;
    static const int horizontalFader18_pngSize;
    juce::Image cachedImage_horizontalFader18_png_1;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DaKog_LookandFeel)
};
