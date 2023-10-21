/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.8

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "..\PluginProcessor.h"
#include "DaKog_LookAndFeel.h"
//[/Headers]

#include "DaKog_RotorSlider.h"
#include "DaKog_RotorSlider.h"
#include "DaKog_VerticalSlider.h"
#include "DaKog_VerticalSlider.h"
#include "DaKog_VerticalSlider.h"
#include "DaKog_RotorSlider.h"
#include "DaKog_RotorSlider.h"
#include "DaKog_VerticalSlider.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class GUI  : public juce::Component
{
public:
    //==============================================================================
    GUI ();
    ~GUI() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>
        AttachAndSetupSlider(const juce::String& ID,
        juce::AudioProcessorValueTreeState& parametersTreeState);

    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> AttachAndSetupButton(const juce::String& parameterID,
        juce::AudioProcessorValueTreeState& parametersTreeState);
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;

    // Binary resources:
    static const char* _800600_backGround_png;
    static const int _800600_backGround_pngSize;
    static const char* blackSquare_png;
    static const int blackSquare_pngSize;
    static const char* title800_png;
    static const int title800_pngSize;
    static const char* hiPassCurve_png;
    static const int hiPassCurve_pngSize;
    static const char* lowPassCurve_png;
    static const int lowPassCurve_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    struct RotorTextDefinition
    {
        juce::String m_LeftValue;
        juce::String m_RightValue;
        juce::String m_RotorLabel;
        juce::String m_ToolTip;
        juce::String m_ValueSuffix;
        RotorTextDefinition(const char* leftValue, const char* rightValue, const char* rotorLabel, const char* tooltip,
            const char* suffix) :
            m_LeftValue(leftValue),
            m_RightValue(rightValue),
            m_RotorLabel(rotorLabel),
            m_ToolTip(tooltip),
            m_ValueSuffix(suffix)
        {};
        RotorTextDefinition(){};

    };

    struct VerticalSliderTextDefinition
    {
        juce::String m_BottomText;
        juce::String m_ToolTip;
        juce::String m_ValueSuffix;
        VerticalSliderTextDefinition(const char* bottomText, const char* toolTip, const char* suffix) :
            m_BottomText(bottomText),
            m_ToolTip(toolTip),
            m_ValueSuffix(suffix)
        {};
        VerticalSliderTextDefinition() {};

    };
    std::map<juce::String, RotorTextDefinition> m_RotorTextDefinitions;
    std::map<juce::String, VerticalSliderTextDefinition> m_VerticalSliderTextDefinitions;
    DaKog_LookandFeel m_LookAndFeel;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::GroupComponent> m_OutputMixGroup;
    std::unique_ptr<juce::GroupComponent> m_InputMixGroup;
    std::unique_ptr<juce::GroupComponent> m_DriveGroup;
    std::unique_ptr<juce::GroupComponent> m_SineWaveGroup;
    std::unique_ptr<DaKog_RotorSlider> m_DriveRotor;
    std::unique_ptr<DaKog_RotorSlider> m_ClippingFactorRotor;
    std::unique_ptr<juce::Slider> m_SineFrequency;
    std::unique_ptr<juce::GroupComponent> m_FilterGroup;
    std::unique_ptr<DaKog_VerticalSlider> m_WetGain;
    std::unique_ptr<DaKog_VerticalSlider> m_Mix;
    std::unique_ptr<DaKog_VerticalSlider> m_OutPut;
    std::unique_ptr<DaKog_RotorSlider> m_LoPassFilterRotor;
    std::unique_ptr<DaKog_RotorSlider> m_HighPassFilterRotor;
    std::unique_ptr<juce::Slider> m_SineWaveMix;
    std::unique_ptr<juce::ToggleButton> m_SineToggle;
    std::unique_ptr<DaKog_VerticalSlider> m_InputSlider;
    std::unique_ptr<juce::Label> m_Version;
    std::unique_ptr<juce::Label> m_SineMix;
    juce::Image cachedImage__800600_backGround_png_1;
    juce::Image cachedImage_blackSquare_png_2;
    juce::Image cachedImage_title800_png_3;
    juce::Image cachedImage_hiPassCurve_png_4;
    juce::Image cachedImage_lowPassCurve_png_5;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GUI)
};

//[EndFile] You can add extra defines here...

//[/EndFile]

