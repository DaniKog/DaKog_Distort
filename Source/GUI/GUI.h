/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.2

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
#include "DaKog_VerticalSlider.h"
#include "DaKog_RotorSlider.h"
#include "DaKog_VerticalSlider.h"
#include "DaKog_VerticalSlider.h"
#include "DaKog_VerticalSlider.h"
#include "DaKog_RotorSlider.h"
#include "DaKog_RotorSlider.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class GUI  : public juce::Component,
             public juce::Slider::Listener
{
public:
    //==============================================================================
    GUI ();
    ~GUI() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>
        AttachSlider(const juce::String& ID,
        juce::AudioProcessorValueTreeState& parametersTreeState);
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;

    // Binary resources:
    static const char* _800600_backGround_png;
    static const int _800600_backGround_pngSize;
    static const char* blackSquare_png;
    static const int blackSquare_pngSize;
    static const char* title800_png;
    static const int title800_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //DaKog_DistortAudioProcessor& audioProcessor;
    DaKog_LookandFeel m_LookAndFeel;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::GroupComponent> m_DriveGroup4;
    std::unique_ptr<juce::GroupComponent> m_DriveGroup3;
    std::unique_ptr<juce::GroupComponent> m_DriveGroup;
    std::unique_ptr<juce::GroupComponent> m_DriveGroup2;
    std::unique_ptr<DaKog_RotorSlider> m_DriveRotor;
    std::unique_ptr<DaKog_VerticalSlider> m_InputSlider;
    std::unique_ptr<DaKog_RotorSlider> m_ClippingFactorRotor;
    std::unique_ptr<juce::Slider> m_SineFrequency;
    std::unique_ptr<juce::GroupComponent> m_FilterGroup;
    std::unique_ptr<DaKog_VerticalSlider> m_WetGain;
    std::unique_ptr<DaKog_VerticalSlider> m_Mix;
    std::unique_ptr<DaKog_VerticalSlider> m_OutPut;
    std::unique_ptr<DaKog_RotorSlider> m_LoPassFilterRotor;
    std::unique_ptr<DaKog_RotorSlider> m_HighPassFilterRotor;
    std::unique_ptr<juce::Slider> juce__slider;
    std::unique_ptr<juce::ToggleButton> m_SineToggle;
    juce::Image cachedImage__800600_backGround_png_1;
    juce::Image cachedImage_blackSquare_png_2;
    juce::Image cachedImage_title800_png_3;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

