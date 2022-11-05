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
    juce::Slider& GetSlider() { return *DaKog_Silder.get();}
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;

    // Binary resources:
    static const char* button_png;
    static const int button_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> DaKog_Silder;
    std::unique_ptr<juce::Label> m_LeftLabel;
    std::unique_ptr<juce::Label> m_LeftLabel2;
    juce::Image cachedImage_button_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DaKog_RotorSlider)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

