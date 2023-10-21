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
#include "DaKog_LookAndFeel.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class DaKog_RotorSlider  : public juce::Component
{
public:
    //==============================================================================
    DaKog_RotorSlider ();
    ~DaKog_RotorSlider() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    juce::Slider& GetSlider() { return *m_DaKogRotorSilder.get();}
    DaKog_LookandFeel m_LookAndFeel;
    void SetLeftLabel(juce::String& text) { m_LeftLabel.get()->setText(text,juce::NotificationType::dontSendNotification); }
    void SetRightLabel(juce::String& text) { m_RightLabel.get()->setText(text,juce::NotificationType::dontSendNotification); }
    void SetRotorLabel(juce::String& text) { m_RotorLabel.get()->setText(text,juce::NotificationType::dontSendNotification); }
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Label> m_RotorLabel;
    std::unique_ptr<juce::Slider> m_DaKogRotorSilder;
    std::unique_ptr<juce::Label> m_LeftLabel;
    std::unique_ptr<juce::Label> m_RightLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DaKog_RotorSlider)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

