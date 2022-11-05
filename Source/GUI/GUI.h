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
        AttachSlider(const juce::String& ID,
        juce::AudioProcessorValueTreeState& parametersTreeState);

    void SetDebugText(const juce::String& string) { WowLabel2->setText(string, juce::NotificationType::dontSendNotification); WowLabel2->repaint(); }
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;

    // Binary resources:
    static const char* _800600_backGround_png;
    static const int _800600_backGround_pngSize;
    static const char* blackSquare_png;
    static const int blackSquare_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //DaKog_DistortAudioProcessor& audioProcessor;
    DaKog_LookandFeel m_LookAndFeel;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> m_DriveSlider;
    std::unique_ptr<juce::Label> juce__label;
    std::unique_ptr<juce::Label> WowLabel2;
    juce::Image cachedImage__800600_backGround_png_1;
    juce::Image cachedImage_blackSquare_png_2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

